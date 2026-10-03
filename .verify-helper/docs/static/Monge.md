# 2 変数関数における単調性

## Monge 行列

$A$ を $n \times m$ 行列 ($A_{i,j}$ は全順序可換群 $G$ の元) とする.

$A$ が **Monge 行列** であるとは, 任意の $0 \leq i_1 < i_2 < n$, $0 \leq j_1 < j_2 < m$ に対して

$$ A_{i_1,j_1} + A_{i_2,j_2} \leq A_{i_1,j_2} + A_{i_2,j_1} $$

が成り立つことである. 不等号が逆向きのものは **逆 Monge 行列** という.

### 隣接する成分による特徴づけ

$A$ が Monge 行列であることは, 任意の $0 \leq i < n - 1$, $0 \leq j < m - 1$ に対して

$$ A_{i,j} + A_{i+1,j+1} \leq A_{i,j+1} + A_{i+1,j} $$

が成り立つことと同値である. ($\Rightarrow$ は明らか. $\Leftarrow$ は, 隣接する $2 \times 2$ 部分行列の不等式を $i_2 - i_1$, $j_2 - j_1$ について足し合わせればよい.)

これにより, Monge 行列であるかの判定が $O(nm)$ 時間でできる.

## Monotone 行列

$A$ を $n \times m$ 行列とする. 各行 $i$ に対して, $A_{i,j}$ を最小にする $j$ のうち最小のものを $j^\ast(i)$ とする.

$A$ が **Monotone** であるとは,

$$ j^\ast(0) \leq j^\ast(1) \leq \dots \leq j^\ast(n - 1) $$

が成り立つことである. これは, [Monotone Minima](/library_for_cpp/Queries/Monotone_Minima.html) が仮定する条件そのものである.

### Monge ならば Monotone

**命題**: Monge 行列は Monotone である.

**証明**: Monge 行列 $A$ が Monotone でないと仮定する. このとき, ある $i_1 < i_2$ で $j_1 := j^\ast(i_2) < j^\ast(i_1) =: j_2$ となる. $j^\ast(i_1)$ の定め方 ($j_1 < j_2$ に注意) より $A_{i_1,j_2} < A_{i_1,j_1}$, $j^\ast(i_2)$ の定め方より $A_{i_2,j_1} \leq A_{i_2,j_2}$ である. 一方, $A$ が Monge 行列であることから $i_1 < i_2$, $j_1 < j_2$ に対して

$$ A_{i_1,j_1} + A_{i_2,j_2} \leq A_{i_1,j_2} + A_{i_2,j_1} $$

であり, 整理すると $A_{i_1,j_1} - A_{i_1,j_2} \leq A_{i_2,j_1} - A_{i_2,j_2} \leq 0$ となる. これは $A_{i_1,j_2} < A_{i_1,j_1}$ に矛盾する. $\square$

## 全単調行列

$n \times m$ 行列 $A$ が **全単調** (totally monotone) であるとは, 任意の $0 \leq i_1 < i_2 < n$, $0 \leq j_1 < j_2 < m$ に対して

$$ A_{i_1,j_1} > A_{i_1,j_2} \implies A_{i_2,j_1} > A_{i_2,j_2} $$

が成り立つことである. すなわち, ある $2 \times 2$ 部分行列で, 上の行が「右の方が小さい」ならば, 下の行も「右の方が小さい」ということである.

この条件は $2 \times 2$ 部分行列に対するものなので, 全単調行列の部分行列は全単調行列である.

### Monge, 全単調, Monotone の関係

以下が成り立つ.

$$ \text{Monge} \implies \text{全単調} \implies \text{Monotone} $$

また, 全単調であることは, 「任意の部分行列が Monotone である」ことと同値である.

**命題 1**: Monge 行列は全単調である.

**証明**: $i_1 < i_2$, $j_1 < j_2$ について $A_{i_1,j_1} > A_{i_1,j_2}$ とする. $A$ が Monge 行列であることから

$$ A_{i_1,j_1} - A_{i_1,j_2} \leq A_{i_2,j_1} - A_{i_2,j_2} $$

であり, 左辺は正であるから, $A_{i_2,j_1} - A_{i_2,j_2} > 0$ すなわち $A_{i_2,j_1} > A_{i_2,j_2}$ である. $\square$

**命題 2**: 全単調行列は Monotone である.

**証明**: 全単調行列 $A$ が Monotone でないと仮定すると, ある $i_1 < i_2$ で $j_1 := j^\ast(i_2) < j^\ast(i_1) =: j_2$ となる. $j^\ast(i_1)$ の定め方 ($j_1 < j_2$ に注意) より $A_{i_1,j_1} > A_{i_1,j_2}$ である. 全単調性より $A_{i_2,j_1} > A_{i_2,j_2}$ となるが, これは $j_1$ が第 $i_2$ 行の最小値を与えること ($A_{i_2,j_1} \leq A_{i_2,j_2}$) に矛盾する. $\square$

**命題 3**: $A$ が全単調であることと, $A$ の任意の部分行列が Monotone であることは同値である.

**証明**: ($\Rightarrow$) 全単調行列の部分行列は全単調であり, 命題 2 より Monotone である.

($\Leftarrow$) $i_1 < i_2$, $j_1 < j_2$ について $A_{i_1,j_1} > A_{i_1,j_2}$ とする. 行 $i_1, i_2$, 列 $j_1, j_2$ からなる $2 \times 2$ 部分行列を考えると, その第 $1$ 行 (行 $i_1$) の最小値のうち最小の位置は $j_2$ である. この部分行列は Monotone であるから, 第 $2$ 行 (行 $i_2$) の最小値のうち最小の位置も $j_2$ 以上, すなわち $j_2$ である. これは $A_{i_2,j_2} < A_{i_2,j_1}$ を意味する. $\square$

### 逆は成り立たない

* **全単調だが Monge でない例**: $2 \times 2$ 行列で $A_{0,0} = 0$, $A_{0,1} = 1$, $A_{1,0} = 0$, $A_{1,1} = 10$ のとき, $A_{0,0} > A_{0,1}$ とならないので全単調であるが, $A_{0,0} + A_{1,1} = 10 > 1 = A_{0,1} + A_{1,0}$ なので Monge ではない.
* **Monotone だが全単調でない例**: $2 \times 3$ 行列で $A_{0,0} = 0$, $A_{0,1} = 5$, $A_{0,2} = 3$, $A_{1,0} = 9$, $A_{1,1} = 1$, $A_{1,2} = 2$ のとき, $j^\ast(0) = 0 \leq 1 = j^\ast(1)$ なので Monotone であるが, 列 $1, 2$ について $A_{0,1} > A_{0,2}$ かつ $A_{1,1} \leq A_{1,2}$ なので全単調ではない.

[Monotone Minima](/library_for_cpp/Queries/Monotone_Minima.html) は Monotone であれば使える. 一方, 全単調であれば, より高速な SMAWK が使える.

## 性質

* $A, B$ が Monge 行列, $c \geq 0$ ならば, $A + B$, $cA$ も Monge 行列である.
* 任意の $u_0, \dots, u_{n-1}$ と $v_0, \dots, v_{m-1}$ に対して, $A_{i,j} + u_i + v_j$ も Monge 行列である. (不等式の両辺で $u_{i_1}, u_{i_2}, v_{j_1}, v_{j_2}$ が相殺される.)
* Monge 行列の部分行列 (行と列をそれぞれ部分集合に制限したもの) も Monge 行列である.

## アルゴリズム

Monge 行列 $A$ ($n \times m$) の各行の最小値の位置 $j^\ast(i)$ は, 行列を全て作らず, $A_{i,j}$ を $O(1)$ 時間で評価できるとき, 以下で求められる.

|アルゴリズム|計算量|
|:---:|:---:|
|[Monotone Minima](/library_for_cpp/Queries/Monotone_Minima.html)| $O(n + m \log n)$ |
|SMAWK| $O(n + m)$ |

愚直には $O(nm)$ 時間かかるので, これを高速化できる.

## 例

### 凸関数の差

$\varphi: \mathbb{Z} \to G$ が下に凸であるとき, $A_{i,j} := \varphi(i - j)$ は Monge 行列である.

実際, $i_1 < i_2$, $j_1 < j_2$ に対して, $i_1 - j_2$ が最小, $i_2 - j_1$ が最大で, $i_1 - j_1$ と $i_2 - j_2$ はその間にあり, 和が等しい. よって $\varphi$ の凸性から

$$ \varphi(i_1 - j_1) + \varphi(i_2 - j_2) \leq \varphi(i_1 - j_2) + \varphi(i_2 - j_1) $$

である. ($\varphi$ の定義域外は $+\infty$ とみなすと, 帯状の領域になり, 性質は保たれる.)

#### (min, +) 畳み込み

$f$ を下に凸な列, $g$ を任意の列とする. 上の例と, 性質 (各列に値を加えても Monge 行列のまま) より, $A_{k,j} := f(k - j) + g(j)$ は Monge 行列である.

$(\min, +)$ 畳み込み $h(k) = \min_{i + j = k} (f(i) + g(j))$ は, $A$ の各行の最小値であるから, Monotone Minima によって求められる.

* [Min_Plus_Convolution_Convex_Arbitrary](/library_for_cpp/Convolution/Min_Plus_Convolution_Convex_Arbitrary.html): 凸 $\times$ 任意
* [Min_Plus_Convolution_Convex](/library_for_cpp/Convolution/Min_Plus_Convolution_Convex.html): 凸 $\times$ 凸 ($O(n + m)$ 時間)

### 区間のコストが凸な DP

$D_j = \min_{i < j} (D_i + w(i, j))$ において, コスト $w$ が Monge 性 $w(i_1, j_1) + w(i_2, j_2) \leq w(i_1, j_2) + w(i_2, j_1)$ ($i_1 < i_2 < j_1 < j_2$) を満たすとき, 遷移元の最適な位置は単調になる.

## 参考

* 各行の最小値の位置を求めるアルゴリズム (SMAWK): Aggarwal, Klawe, Moran, Shor, Wilber, "Geometric applications of a matrix-searching algorithm", Algorithmica 2, 1987.
