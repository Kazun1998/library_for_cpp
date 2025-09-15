#pragma once

#include"base.hpp"

namespace geometry {
    template<typename R>
    class Point {
        public:
        R x, y;

        public:
        Point(): x(0), y(0) {}
        Point(R _x, R _y): x(_x), y(_y) {}

        // 加法
        Point& operator+=(const Point &B){
            x += B.x;
            y += B.y;
            return *this;
        }

        friend Point operator+(const Point &P, const Point &Q) { return Point(P) += Q; }

        // 減法
        Point& operator-=(const Point &B){
            x -= B.x;
            y -= B.y;
            return *this;
        }

        friend Point operator-(const Point &P, const Point &Q) { return Point(P) -= Q; }

        // スカラー倍
        Point& operator*=(const R &a){
            x *= a;
            y *= a;
            return *this;
        }

        friend Point operator*(const Point &P, const R &a) { return Point(P) *= a; }
        friend Point operator*(const R &a, const Point &P) { return Point(P) *= a; }

        friend istream& operator>>(istream &is, Point &P) {
            R a, b;
            is >> a >> b;
            P = Point(a, b);
            return is;
        }

        friend ostream& operator<<(ostream &os, const Point &P) {
            return os << P.x << " " << P.y;
        }

        inline R norm_2() const { return x * x + y * y; }
        inline double norm() const { return sqrt(norm_2()); }
        inline R dot(const Point B) const { return x * B.x + y * B.y; }
        inline R det(const Point B) const { return x * B.y - y * B.x; }
    };

    template<typename R>
    inline R dot(const Point<R> &A, const Point<R> &B) { return A.x * B.x + A.y * B.y; }

    template<typename R>
    inline R cross(const Point<R> &A, const Point<R> &B) { return A.x * B.y - A.y * B.x; }

    template<typename R>
    inline R norm_2(const Point<R> &P) { return dot(P, P); }

    template<typename R>
    inline double norm(const Point<R> &P) { return sqrt(norm_2(P)); }
}
