#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include"../../template/template.hpp"
#include"../../Algebra/Permutaion.hpp"

void verify() {
    // Constructor & Identity
    {
        Permutation p(5);
        assert(p.inversion() == 0);
        assert(p.sign() == 1);
        auto cycles = p.cycle_division();
        assert(cycles.size() == 5);
    }
    
    {
        Permutation p = Permutation::identity(3);
        assert(p.inversion() == 0);
    }

    // Vector Constructor & Inversion & Sign
    {
        vector<int> v = {2, 0, 1};
        Permutation p(v);
        assert(p.inversion() == 2);
        assert(p.sign() == 1);
        
        vector<int> v2 = {2, 1, 0};
        Permutation p2(v2);
        assert(p2.inversion() == 3);
        assert(p2.sign() == -1);
    }

    // Multiplication (Composition)
    {
        vector<int> v1 = {1, 2, 0};
        vector<int> v2 = {0, 2, 1};
        Permutation p(v1);
        Permutation q(v2);
        Permutation r = p * q;
        
        assert(r.inversion() == 1);
        
        auto cycles = r.cycle_division();
        assert(cycles.size() == 2);
    }

    // Inverse
    {
        vector<int> v = {2, 0, 1};
        Permutation p(v);
        Permutation inv = p.inverse();
        
        Permutation id = p * inv;
        assert(id.inversion() == 0);
        
        Permutation id2 = inv * p;
        assert(id2.inversion() == 0);
    }

    // Swap & Transposition
    {
        Permutation p(4);
        p.swap(1, 3);
        assert(p.inversion() == 3);

        Permutation q(3);
        q.transposition(0, 2);
        assert(q.inversion() == 3);
        
        q.transposition(1, 2);
        assert(q.inversion() == 2);
    }

    // Minimum Transposition
    {
        vector<int> v = {2, 0, 1};
        Permutation p(v);
        assert(p.minimum_transposition() == 2);
    }

    // list_inversion
    {
        vector<int> A = {10, 20, 30};
        vector<int> B = {20, 30, 10};
        auto res = list_inversion(A, B);
        assert(res.has_value());
        assert(res.value() == 2);
        
        vector<int> C = {1, 1, 2};
        vector<int> D = {1, 2, 1};
        assert(list_inversion(C, D).value() == 1);
        
        vector<int> E = {1, 2};
        vector<int> F = {1, 3};
        assert(!list_inversion(E, F).has_value());
    }
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
