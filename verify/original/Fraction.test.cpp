#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template/template.hpp"
#include "../../Algebra/Fraction.hpp"

void verify() {
    // Constructor & Normalize
    {
        Fraction<long long> f1(2, 4);
        assert(f1.num == 1 && f1.den == 2);

        Fraction<long long> f2(2, -4);
        assert(f2.num == -1 && f2.den == 2);

        Fraction<long long> f3(-2, -4);
        assert(f3.num == 1 && f3.den == 2);

        Fraction<long long> f4(0, 5);
        assert(f4.num == 0 && f4.den == 1);

        Fraction<long long> f5(5);
        assert(f5.num == 5 && f5.den == 1);
    }

    // Arithmetic
    {
        Fraction<long long> a(1, 2);
        Fraction<long long> b(1, 3);

        assert(a + b == Fraction<long long>(5, 6));
        assert(a - b == Fraction<long long>(1, 6));
        assert(a * b == Fraction<long long>(1, 6));
        assert(a / b == Fraction<long long>(3, 2));

        Fraction<long long> c = a;
        c += b;
        assert(c == Fraction<long long>(5, 6));

        c = a;
        c -= b;
        assert(c == Fraction<long long>(1, 6));

        c = a;
        c *= b;
        assert(c == Fraction<long long>(1, 6));

        c = a;
        c /= b;
        assert(c == Fraction<long long>(3, 2));
    }

    // Comparison
    {
        Fraction<long long> a(1, 2);
        Fraction<long long> b(2, 4);
        Fraction<long long> c(1, 3);

        assert(a == b);
        assert(a != c);
        assert(c < a);
        assert(a > c);
        assert(a >= b);
        assert(a <= b);
    }

    // Unary -
    {
        Fraction<long long> a(1, 2);
        assert(-a == Fraction<long long>(-1, 2));
    }

    // inv
    {
        Fraction<long long> a(2, 3);
        assert(a.inv() == Fraction<long long>(3, 2));
    }

    // abs
    {
        Fraction<long long> a(-1, 2);
        assert(abs(a) == Fraction<long long>(1, 2));
        assert(abs(Fraction<long long>(1, 2)) == Fraction<long long>(1, 2));
    }

    // pow
    {
        Fraction<long long> a(2, 3);
        assert(pow(a, 0) == Fraction<long long>(1));
        assert(pow(a, 1) == a);
        assert(pow(a, 2) == Fraction<long long>(4, 9));
        assert(pow(a, -1) == Fraction<long long>(3, 2));
        assert(pow(a, -2) == Fraction<long long>(9, 4));
    }

    // to_double
    {
        Fraction<long long> a(1, 2);
        assert(std::abs(a.to_double() - 0.5) < 1e-9);
    }
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
