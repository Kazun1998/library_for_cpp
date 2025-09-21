#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#include"../../../template/template.hpp"
#include"../../../Integer/Euler_Totient.hpp"

int main(){
    int n; cin >> n;
    cout << Euler_Totient(n) << endl;
}
