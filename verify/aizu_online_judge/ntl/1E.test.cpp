#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include"../../../template/template.hpp"

int main(){
    int a, b; cin >> a >> b;
    auto [x, y, ignore] = Extended_Euclid(a, b);
    cout << x << " " << y << endl;
}
