#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B"

#include"../../../template/template.hpp"
#include"../../../Geometry/intersection/Intersection_Segment_and_Segment.hpp"

using namespace geometry;

int main() {
    using namespace geometry;

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        Segment<int> s, t; cin >> s.A >> s.B >> t.A >> t.B;

        cout << has_Intersection(s, t) << endl;
    }
}
