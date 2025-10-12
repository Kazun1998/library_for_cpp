#pragma once

#include"../template/template.hpp"

namespace convolution {
    template<typename R>
    class Convolution_Base {
        protected:
        std::vector<R> data;

        public:
        Convolution_Base() = default;
        Convolution_Base(std::vector<R> data_in): data(std::move(data_in)) {}
        
        Convolution_Base(size_t n): data(std::vector<R>(n)) {} 
        
        // 加法 (+=)
        Convolution_Base& operator+=(const Convolution_Base<R> &B) {
            if(data.size() != B.data.size()) { throw std::length_error("Convolution operands must have the same size."); }

            for (size_t i = 0; i < data.size(); i++) { data[i] += B.data[i]; }
            return *this;
        }

        // 減法 (-=)
        Convolution_Base& operator-=(const Convolution_Base<R> &B) {
            if(data.size() != B.data.size()) { throw std::length_error("Convolution operands must have the same size."); }
            for (size_t i = 0; i < data.size(); i++) { data[i] -= B.data[i]; }
            return *this;
        }

        // スカラー倍 (*=)
        Convolution_Base& operator*=(const R &a) {
            for (size_t i = 0; i < data.size(); i++) { data[i] *= a; }
            return *this;
        }

        virtual Convolution_Base<R>& operator*=(const Convolution_Base<R> &B) = 0;

        inline size_t size() const { return data.size(); }

        inline R& operator[](size_t k) { return data[k]; }
        inline const R& operator[](size_t k) const { return data[k]; }

        const std::vector<R>& to_vector() const { return data; }
    };
}
