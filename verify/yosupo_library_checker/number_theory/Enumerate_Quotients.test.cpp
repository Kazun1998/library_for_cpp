#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Integer/Quotients.hpp"

int main() {
    ll N; cin >> N;
    auto quotients = Quotients(N);

    reverse(quotients.begin(), quotients.end());
    cout << quotients.size() << endl;
    for (int i = 0; i < quotients.size(); i ++) {
        cout << get<0>(quotients[i]) << (i < quotients.size() ? " " : "");
    }
    cout << endl;
}
