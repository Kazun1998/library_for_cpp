#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include"../../../template/template.hpp"
#include"../../../Geometry/Argument_Sort.hpp"

using namespace geometry;

int main() {
    int N; cin >> N;
    vector<Point<ll>> P(N); cin >> P;

    Argument_Sort(P);

    for (int i = 0; i < N; i++) { cout << P[i] << endl; }
}
