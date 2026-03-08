#pragma once

#include"../Algebra/Extended_Algebra.hpp"
#include"Max_Flow.hpp"

namespace projection_selection_problem {
    template<typename T>
    class Project_Selection_Problem {
        using ET = Extended_Algebra<T>;
        using V = int;

        private:
        int N, ver_num;
        V source, target;
        ET base;
        vector<vector<ET>> indivi;
        vector<pair<pair<V, V>, ET>> mutual;
        vector<vector<bool>> guard;

        V add_vertex_inner() {
            V n = ver_num++;
            indivi.emplace_back(vector<ET>{ET(0), ET(0)});
            guard.emplace_back(vector<bool>{true, true});
            return n;
        }

        public:
        ET ans;
        vector<bool> choice;
        Project_Selection_Problem(const int N):
            N(N), ver_num(N + 2), source(N), target(N + 1),
            base(0), indivi(N + 2, { ET(0), ET(0) }), guard(N + 2, {false, false})
            {}

        V add_vertex() {
            V n = ver_num++;
            indivi.emplace_back(vector<ET>{ET(0), ET(0)});
            guard.emplace_back(vector<bool>{false, false});
            return n;
        }

        vector<V> add_vertices(const int k) {
            vector<V> ids;
            for (int i = 1; i <= k; i++) {
                ids.emplace_back(add_vertex());
            }

            return ids;
        }

        void set_zero_one(const V x, const V y, ET a) {
            assert(a.is_negative(true));

            pair<V, V> arc(x, y);
            mutual.emplace_back(arc, -a);
        }

        inline void set_zero(const V x, const ET a) { indivi[x][0] += a; }
        inline void set_one(const V x, const ET a) { indivi[x][1] += a; }

        void set_all_zero(const vector<V>& Xs, const ET a) {
            assert(a.is_positive(true));

            V k = add_vertex_inner();
            base += a;

            indivi[k][0] -= a;
            guard[k][0] = false;

            for(V x: Xs) {
                pair<V, V> arc(k, x);
                mutual.emplace_back(arc, ET::inf);
            }
        }

        void set_all_one(const vector<V>& Xs, const ET a) {
            assert(a.is_positive());

            V k = add_vertex_inner();
            base += a;

            indivi[k][1] -= a;
            guard[k][1] = false;

            for(V x: Xs) {
                pair<V, V> arc(x, k);
                mutual.emplace_back(arc, ET::inf);
            }
        }

        void set_not_equal(const V x, const V y, const ET a) {
            assert(a.is_negative(true));

            set_zero_one(x, y, a);
            set_zero_one(y, x, a);
        }

        void set_equal(const V x, const V y, const ET a) {
            set_all_zero({x, y}, a);
            set_all_one({x, y}, a);
        }

        void ban_zero(const V x) { set_zero(x, -ET::inf); }
        void ban_one(const V x) { set_one(x, -ET::inf); }

        void force_zero(const V x) { ban_one(x); }
        void force_one(const V x) { ban_zero(x); }

        void solve() {
            max_flow::Max_Flow<ET> F(ver_num);

            for (int i = 0; i < N; i++) {
                F.add_arc(source, i, 0);
                F.add_arc(i, target, 0);

                if (indivi[i][0].is_positive(true)) {
                    base += indivi[i][0];
                    F.add_arc(source, i, indivi[i][0]);
                } else {
                    F.add_arc(i, target, -indivi[i][0]);
                }

                if (indivi[i][1].is_positive(true)) {
                    base += indivi[i][1];
                    F.add_arc(i, target, indivi[i][1]);
                } else {
                    F.add_arc(source, i, -indivi[i][1]);
                }
            }

            for (int i = target + 1; i < ver_num; i++) {
                if (!guard[i][0]) { F.add_arc(source, i, -indivi[i][0]); }
                if (!guard[i][1]) { F.add_arc(i, target, -indivi[i][1]); }
            }

            for(auto &[arc, a]: mutual) {
                V x, y;
                tie(x, y) = arc;
                F.add_arc(x, y, a);
            }

            ET alpha = F.max_flow(source, target);
            ans = base - alpha;
            choice = F.min_cut(source);
        }
    };
}
