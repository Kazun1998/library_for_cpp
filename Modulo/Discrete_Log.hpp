#include"Modulo.hpp"

namespace modulo {
    long long Discrete_Log (Modulo &X, Modulo &Y, long long not_exist = -1) {
        assert(X.n == Y.n);

        long long m = 0;
        for (; m * m < X.n; m++) {}

        auto y = Modulo(Y);
        unordered_set<long long> st;
        for (int i = 0; i < m; i++) {
            y *= X;
            st.insert(y.a);
        }

        auto step = pow(X, m);
        auto head = Modulo(1, X.n);
        int count = 0;

        for (int k = 1; k <= m; k++) {
            auto tail = head;
            head *= step;
            if (!st.count(head.a)) { continue; }

            auto body = tail;
            for (long long n = (k - 1) * m; n < k * m; n++) {
                if (body == Y) { return n; }

                body *= X;
            }

            count++;

            if (count == 2) { return not_exist; }
        }

        return not_exist;
    }
}
