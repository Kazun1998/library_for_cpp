---
title: Stern Brocot 木
documentation_of: //Math/Stern_Brocot_Tree.hpp
---

## Outline

Stern Brocot 木に関する計算を行うメソッドをまとめたクラス.

## Define

$\widehat{\mathbb{Q}_{+0}} := \\\\{x \geq 0 \mid x \in \mathbb{Q} \\\\} \cup \\\\{ \infty \\\\}$ とする. 次のようにして, 根付き木である Stern Brocot 木 $T = (V, E)$ を次のようにして形式的に定義する. なお, 形式的に $\frac{1}{0} := \infty$ とする.

$\widehat{\mathbb{Q}_{+0}}$ の開区間 $v := \left(\frac{a}{b}, \frac{c}{d} \right)$ に対して, $v$ のメジアン $\varphi(v)$ を

$$ \varphi(v) := \frac{a+c}{b+d} $$

で定義することにする.

* $T$ の各頂点は $\widehat{\mathbb{Q}_{+0}}$ の閉区間である.
* $T$ の根は $(0, \infty)$ である.
* 次のようにして, 頂点 $v = \left(\frac{a}{b}, \frac{c}{d} \right)$ の子を生成する.
  * $v$ の左の子は $\left(\frac{a}{b}, \varphi(v) \right)$, $v$ の右の子 $\left(\varphi(v), \frac{c}{d} \right)$ になる.

## Theory

Stern Brocot 木 $T$ について, 以下が成り立つ.

* **既約** 分数 $\frac{a}{b}, \frac{c}{d} \in \widehat{\mathbb{Q}_{+0}}$ に対して, 以下は同値になる.
  * $v := \left(\frac{a}{b}, \frac{c}{d} \right) \in V$.
  * $ad-bc=1$.
* 任意の正の有理数 $x \in \mathbb{Q}_+$ に対して, $\varphi(v) = x$ となる $v \in V$ がただ一つ存在する.

## Contents

以降の説明では, $v \in V$ と $\varphi(v) \in \mathbb{Q}_{+}$ が一対一対応にあるため, これを同一視することがある.

以下の型エイリアスを定義する.
```cpp
using Fraction = pair<ll, ll>;

template<typename Direction>
using Path = vector<pair<Direction, ll>>;
```

特に, `Fraction` については, `first` が分子, `second` が分母を表す.

### encode

```cpp
template<typename Direction>
Path<Direction> encode(ll a, ll b, Direction left, Direction right)
```

* $T$ における頂点 $\frac{a}{b}$ への行き方を求める.
* **返り値** : 以下の要件を満たす各要素が `pair<Direction, ll>` であるリスト.
  * リストの中の要素 $(d, k)$ について, $d = $`left` ならば, $k$ 回連続で左の子に進むことを, $d=$`right` ならば, $k$ 回連続で右の子に進むことを表す.
* **計算量** : $O(\log(a + b))$ 時間.

### decode_interval

```cpp
template<typename Direction>
pair<Fraction, Fraction> decode_interval(Path<Direction> &code, Direction left, Direction right)
```

* $T$ において, `code` の順番で辿った時に到達する $\widehat{\mathbb{Q}_{+0}}$ 上の開区間の端点を求める.
* **入力**
  * `code`: 以下の要件を満たす各要素が `pair<Direction, ll>` であるリスト.
    * リストの中の要素 $(d, k)$ について, $d = $`left` ならば, $k$ 回連続で左の子に進むことを, $d=$`right` ならば, $k$ 回連続で右の子に進むことを表す. 
* **返り値**
  * 第 $1$ 要素が開区間の下限, 第 $2$ 要素が開区間の上限になる.
* **計算量** : `code` の長さを $m$ として, $O(m)$ 時間.

### decode_interval

```cpp
template<typename Direction>
Fraction decode(Path<Direction> &code, Direction left, Direction right)
```

* $T$ において, `code` の順番で辿った時に到達する正の有理数を求める.
* **入力**
  * `code`: 以下の要件を満たす各要素が `pair<Direction, ll>` であるリスト.
    * リストの中の要素 $(d, k)$ について, $d = $`left` ならば, $k$ 回連続で左の子に進むことを, $d=$`right` ならば, $k$ 回連続で右の子に進むことを表す. 
* **計算量** : `code` の長さを $m$ として, $O(m)$ 時間.

### lowest_common_ancestor

```cpp
template<typename Direction>
Fraction lowest_common_ancestor(ll a, ll b, ll c, ll d)
```

* $T$ における $\frac{a}{b}$ と $\frac{c}{d}$ の最小共通祖先を求める.
* **計算量** : $O(\log(a+b+c+d))$ 時間

### ancestor

```cpp
template<typename Direction>
Fraction ancestor(ll a, ll b, ll k, Fraction default_value = {-1, -1})
```

* $T$ における $\frac{a}{b}$ の祖先のうち, 深さがちょうど $k$ であるものを求める. ただし, 存在しない時の返り値は $-1/-1$ とする.
* **計算量** : $O(\log(a+b))$ 時間.

### range

```cpp
template<typename Direction>
pair<Fraction, Fraction> range(ll a, ll b)
```

* $\varphi(v) = a/b$ となる $v \in V$ の下限と上限を求める.
* **返り値**
  * 第 $1$ 要素が開区間の下限, 第 $2$ 要素が開区間の上限になる.
* **計算量** : $O(\log(a+b))$ 時間.



