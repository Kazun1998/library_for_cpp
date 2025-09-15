#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include"../../../template/template.hpp"
#include"../../../Geometry/Counter_Clockwise.hpp"

using namespace geometry;

int main() {
    using namespace geometry;
    Point<ll> A, B; cin >> A >> B;

    int Q; cin >> Q;
    for (int  q= 0; q < Q; q++) {
        Point<ll> P; cin >> P;
        int res = Counter_Clockwise(A, B, P);
        if (res == COUNTER_CLOCKWISE) {
            cout << "COUNTER_CLOCKWISE" << endl;
        } elif (res == CLOCKWISE) {
            cout << "CLOCKWISE" << endl;
        } elif (res == ONLINE_BACK) {
            cout << "ONLINE_BACK" << endl;
        } elif (res == ONLINE_FRONT) {
            cout << "ONLINE_FRONT" << endl;
        } elif (res == ON_SEGMENT) {
            cout << "ON_SEGMENT" << endl;
        }
    }
}
