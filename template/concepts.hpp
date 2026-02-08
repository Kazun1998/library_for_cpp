#pragma once

// 単項演算子コンセプト
template <typename Op, typename X>
concept Unary_Operator_Concept = requires(Op op, const X &x) {
    { op(x) } -> std::convertible_to<X>;
};

// 二項演算子コンセプト
template <typename Op, typename X>
concept Binary_Operator_Concept = requires(Op op,const X &x, const X &y) {
    { op(x, y) } -> std::convertible_to<X>;
};

// モノイドコンセプト
// 二項演算 + 単位元
template <typename M, auto op, auto identity>
concept Monoid_Concept = 
    Binary_Operator_Concept<decltype(op), M>
    && std::convertible_to<decltype(identity), M>;

// 群コンセプト
// モノイド + 逆元
template <typename G, auto op, auto identity, auto inv>
concept Group_Concept = 
    Monoid_Concept<G, op, identity>
    && Unary_Operator_Concept<decltype(inv), G>;

// 順序群コンセプト
// 群 + 全順序
template <typename G, auto op, auto identity, auto inv>
concept Totally_Ordered_Group_Concept = 
    Group_Concept<G, op, identity, inv>
    && totally_ordered<G>;

// ハッシュ可能コンセプト
template<typename T>
concept Hashable = requires(T x) {
    { hash<T>{}(x) } -> convertible_to<size_t>;
};
