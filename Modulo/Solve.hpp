#include"../template/template.hpp"
#include"Composite.hpp"


namespace modulo {
    class NoSolutionException : public std::runtime_error {
    public:
        NoSolutionException(const std::string& message) : std::runtime_error(message) {}
    };

    // 線形合同方程式 ax ≡ b (mod m) を解く.
    Modulo Solve_Congruence_Equation(ll a, ll b, ll m) {
        if (m == 0) { throw "m = 0 は禁止です"; }

        ll g = gcd(a, m);

        // 解の存在判定
        if (b % g) { throw NoSolutionException("解が存在しません."); }

        a /= g; b /= g; m /= g;

        return Modulo(a, m).inverse() * Modulo(b, m);
    }

    // ax ≡ b (mod m) の形の線形連立合同式からなる連立線形連立合同式を解く.
    // equations は (a, b, m) の形からなるタプルの列.
    Modulo Solve_System_of_Congruence_Equations(vector<tuple<ll, ll, ll>> equations) {
        Modulo ans(0, 1);
        for (auto &&[a, b, m]: equations) {
            ans = Composite(ans, Solve_Congruence_Equation(a, b, m));
        }

        return ans;
    } 
}