#pragma once

#include"Field_Vector.hpp"

template<typename F>
class Field_Vector_Space {
    private:
    vector<int> index;
    vector<Field_Vector<F>> basis;
    int n;

    public:
    Field_Vector_Space(const int _n): n(_n) { basis.clear(); }
    Field_Vector_Space(const int _n, const vector<Field_Vector<F>> &vectors): n(_n) {
        for (Field_Vector<F> v: vectors) { add_vector(v); }
    }

    int dimension() const { return basis.size(); }

    bool add_vector(Field_Vector<F> &v) {
        Field_Vector<F> w = projection(v);
        if (w.is_zero()) { return false; }

        int i = 0;
        for (; i < n; i++) { unless(w[i] == 0) { break; } }

        w *= w[i].inverse();
        for (int k = 0; k < basis.size(); k++) {
            basis[k] -= basis[k][i] * w;
        }

        index.emplace_back(i);
        basis.emplace_back(w);
        return true;
    }

    Field_Vector<F> projection(const Field_Vector<F> &v) const {
        Field_Vector<F> w = Field_Vector(v);
        for (int k = 0; k < dimension(); k++) {
            w -= w[index[k]] * basis[k];
        }

        return w;
    }

    vector<Field_Vector<F>> get_basis() const { return basis; }
};
