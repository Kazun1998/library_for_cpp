---
title: Trie 木
documentation_of: //Sequence/Trie.hpp
---

## Outline

列の接頭辞に関する検索を高速に行うことができる Trie 木を提供する.

## Define

$\mathcal{A}$ をアルファベットとする.

$W_1, W_2, \dots, W_n$ に関する Trie 木とは, 以下で定義される根付き木 $(T, r)~(T = (V, E))$ である.

* $V$ は $W_1, \dots, W_n$ の接頭辞全体 (空文字列も含む) である. つまり,

$$ V = \{ \emptyset \} ~\cup~ \bigcup_{i=1}^n \{ v_{i,j} := w_{i,1} \dots w_{i,j} \mid 1 \leq j \leq \lvert w_i \rvert \} $$

である.
* 根 $r$ は空文字列 $\emptyset$ である.
* $T$ における辺は, 長さがちょうど $1$ だけ異なり, 一方が他方の接頭辞になっているとき, そしてそのときに限って結ばれる. つまり,

$$ E := \bigcup_{i=1}^n \{ v_{i,j-1} v_{i,j} \mid 1 \leq j \leq \lvert w_i \rvert \} $$

である.

