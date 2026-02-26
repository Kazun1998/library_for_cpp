#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include"../../../library_for_cpp/template/template.hpp"
#include"../../../library_for_cpp/Functional_Graph/Functional_Graph.hpp"

void verify() {
    vector<int> f = {77, 0, 39, 33, 1, 87, 20, 88, 75, 49, 58, 48, 78, 24, 60, 90, 26, 55, 31, 7, 18, 14, 77, 25, 75, 89, 99, 44, 72, 92, 64, 33, 91, 64, 19, 14, 37, 7, 0, 26, 35, 0, 45, 3, 89, 29, 16, 12, 53, 17, 8, 91, 97, 60, 65, 42, 3, 4, 48, 72, 57, 61, 74, 75, 2, 76, 67, 21, 91, 15, 52, 97, 13, 12, 60, 41, 81, 79, 41, 12, 64, 65, 48, 14, 82, 45, 85, 87, 7, 59, 27, 15, 0, 37, 15, 36, 38, 11, 51, 16};

    Functional_Graph F(f);

    int n = 100, k_max = 100000;
    for (int v = 0; v < n; v++) {
        int w = v;
        for (int k = 0; k <= k_max; k++) {
            if (F.calculate(v, k) == w) {
                w = f[w];
                continue;
            } 

            cerr << "Error" << endl;
            cerr << "v = " << v << ", k = " << k << endl;
            cerr << "expect: " << w << endl;
            cerr << "returns: " << F.calculate(v, k) << endl;
            assert(false);
        }
    }
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
