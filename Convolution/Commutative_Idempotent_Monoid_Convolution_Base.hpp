#pragma once

#include"Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Commutative_Idempotent_Monoid_Convolution_Base: public Convolution_Base<R> {
        // 型エイリアス
        using Base = Convolution_Base<R>;
        using Self = Commutative_Idempotent_Monoid_Convolution_Base<R>;

        using Base::Base;

        public:
        virtual void zeta_transform(std::vector<R> &f) const = 0;
        virtual void mobius_transform(std::vector<R> &g) const = 0;

        Self& operator*=(const Base &B) override {
            if (this->data.size() != B.to_vector().size()) {
                throw std::length_error("Convolution operands must have the same size.");
            }

            std::vector<R> f_copy(this->data); 
            std::vector<R> g_copy(B.to_vector()); 

            this->zeta_transform(f_copy);
            this->zeta_transform(g_copy); 

            for (size_t i = 0; i < f_copy.size(); i++) { 
                f_copy[i] *= g_copy[i]; 
            }

            this->mobius_transform(f_copy);
            this->data = std::move(f_copy);
            return *this;
        }

        void zeta() { zeta_transform(this->data); }
        void mobius() { mobius_transform(this->data); }
    };
}
