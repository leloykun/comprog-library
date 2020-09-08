#ifndef COMPROG_SCC_HPP
#define COMPROG_SCC_HPP 1

#include <algorithm>
#include <comprog/internal_scc>
#include <cassert>
#include <vector>

namespace comprog {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace comprog

#endif  // COMPROG_SCC_HPP
