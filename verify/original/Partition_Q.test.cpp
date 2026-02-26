#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include"../../template/template.hpp"
#include"../../Modulo_Polynomial/Fast_Power_Series.hpp"
#include"../../Modulo_Polynomial/Partition_Q.hpp"

using mint = modint<998244353>;

void verify() {
    vector<mint> Q = Partition_Q<mint>(500000);
    assert(Q[0].is_member(1));
    assert(Q[1].is_member(1));
    assert(Q[2].is_member(1));
    assert(Q[3].is_member(2));
    assert(Q[4].is_member(2));
    assert(Q[5].is_member(3));
    assert(Q[6].is_member(4));
    assert(Q[7].is_member(5));
    assert(Q[8].is_member(6));
    assert(Q[9].is_member(8));
    assert(Q[100000].is_member(335984179));
    assert(Q[200000].is_member(258962519));
    assert(Q[300000].is_member(54117395));
    assert(Q[400000].is_member(806940804));
    assert(Q[500000].is_member(680639926));
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
