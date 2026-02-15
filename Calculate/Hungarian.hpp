#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

template<typename T>
class Hungarian {
    int n, m;
    vector<vector<T>> matrix;
    const T INF = numeric_limits<T>::max();
    vector<T> u, v, minv;
    vector<int> p, way;
    vector<bool> used;

    void step(int &j0) {
        used[j0] = true;
        int i0 = p[j0];
        T delta = INF;
        int j1 = -1;

        for (int j = 0; j < m; ++j) {
            if (!used[j]) {
                T cur = matrix[i0][j] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }
        }

        for (int j = 0; j <= m; ++j) {
            if (used[j]) {
                u[p[j]] += delta;
                v[j] -= delta;
            } else {
                if (minv[j] < INF) minv[j] -= delta;
            }
        }
        j0 = j1;
    }

    void update_matching(int j0) {
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != m);
    }

    void construct_result() {
        total_cost = 0;
        matching.assign(n, -1);
        for (int j = 0; j < m; ++j) {
            int i = p[j];
            if (i != n) {
                matching[i] = j;
                total_cost += matrix[i][j];
            }
        }
    }

    void augment(int s) {
        p[m] = s;
        int j0 = m;

        fill(minv.begin(), minv.end(), INF);
        fill(used.begin(), used.end(), false);

        do {
            step(j0);
        } while (p[j0] != n);

        update_matching(j0);
    }

    public:
    vector<int> matching;
    T total_cost;

    Hungarian(vector<vector<T>> cost_matrix) : matrix(cost_matrix) {
        n = matrix.size();
        m = n == 0 ? 0 : matrix[0].size();

        // initialize
        // 0-based indexing for internal logic, n is dummy
        u.assign(n + 1, 0);
        v.assign(m + 1, 0);
        p.assign(m + 1, n);
        way.assign(m + 1, -1);
        minv.assign(m + 1, INF);
        used.assign(m + 1, false);

        solve();
    }

    void solve() {
        for (int i = 0; i < n; ++i) augment(i);

        construct_result();
    }
};
