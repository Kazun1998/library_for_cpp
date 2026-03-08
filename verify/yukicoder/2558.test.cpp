#define PROBLEM "https://yukicoder.me/problems/no/2558"

#include"../../template/template.hpp"
#include"../../Modulo/Composite.hpp"

using namespace modulo;

int main() {
    Modulo X, Y;
    cin >> X.n >> Y.n >> X.a >> Y.a;
    Modulo Z = Composite(X, Y);
    cout << Z.a << endl;
}
