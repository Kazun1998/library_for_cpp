#pragma once

// マクロの定義
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if
#define unless(cond) if (!(cond))
#define until(cond) while (!(cond))
#define loop while (true)

// オーバーロードマクロ
#define overload2(_1, _2, name, ...) name
#define overload3(_1, _2, _3, name, ...) name
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload5(_1, _2, _3, _4, _5, name, ...) name

// 繰り返し系
#define rep1(n) for (ll i = 0; i < n; i++)
#define rep2(i, n) for (ll i = 0; i < n; i++)
#define rep3(i, a, b) for (ll i = a; i < b; i++)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define foreach1(x, a) for (auto &&x: a)
#define foreach2(x, y, a) for (auto &&[x, y]: a)
#define foreach3(x, y, z, a) for (auto &&[x, y, z]: a)
#define foreach4(x, y, z, w, a) for (auto &&[x, y, z, w]: a)
#define foreach(...) overload5(__VA_ARGS__, foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)
