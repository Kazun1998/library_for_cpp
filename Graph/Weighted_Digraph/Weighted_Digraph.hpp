#pragma once

#include "../Digraph/Digraph.hpp"

// 互換用: 重み付き有向 Graph は digraph::Digraph<W> に統合された.
namespace weighted_digraph {
  template<typename W>
  using Weighted_Arc = digraph::Arc<W>;

  template<typename W>
  using Weighted_Digraph = digraph::Digraph<W>;
}
