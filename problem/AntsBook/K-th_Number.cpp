#include <algorithm>
#include <iostream>
#include <vector>

struct query{
  int from, to;
  int k;
};

std::vector<int> merge(const std::vector<int>& split1, const std::vector<int>& split2) {
  auto split1_size = split1.size();
  auto split2_size = split2.size();
  std::vector<int> result(split1_size + split2_size);
  int split1_select {};
  int split2_select {};
  for (auto i = 0;i < split1_size+split2_size;++i) {
    if (split1_select == split1_size) {
      result[i] = split2[split2_select];
      ++split2_select;
    } else if (split2_select == split2_size) {
      result[i] = split1[split1_select];
      ++split1_select;
    } else {
      if (split1[split1_select] < split2[split2_select]) {
        result[i] = split1[split1_select];
        ++split1_select;
      } else {
        result[i] = split2[split2_select];
        ++split2_select;
      }
    }
  }
  return result;
}
std::vector<int> init(std::vector<std::vector<int>>& segment_data_tree, const std::vector<int>& a, const int& left, const int& right, const int& index) {
  if (left == right) return segment_data_tree[index] = std::vector<int>{a[left]};
  return segment_data_tree[index] = merge(init(segment_data_tree, a, left, (left+right)/2, 2*index+1), init(segment_data_tree, a, (left+right)/2+1, right, 2*index+2));
}

int query_answer(const int& i, const int& j, const int& x, const int& k, const int& l, const int& r, const std::vector<std::vector<int>>& segment_data_tree) {
  if (j <= l || r <= i) {
    return 0;
  } else if (i <= l && r <= j) {
    return std::upper_bound(segment_data_tree[k].begin(), segment_data_tree[k].end(), x) - segment_data_tree[k].begin();
  } else {
    int lc = query_answer(i, j, x, k*2+1, l, (l+r)/2, segment_data_tree);
    int rc = query_answer(i, j, x, k*2+2, (l+r)/2, r, segment_data_tree);
    return lc+rc;
  }
}
void answer(const int& N, const int& M, const std::vector<int>& a, const std::vector<query>& que) {
  std::vector<std::vector<int>> segment_data_tree(2*N);
  init(segment_data_tree, a, 0, a.size()-1, 0);
  std::vector<int> sorted_a = segment_data_tree[0];
  for (const auto& e : que) {
    int lb = -1, ub = N-1;
    while (ub - lb > 1) {
      int md = (ub+lb)/2;
      int c = query_answer(e.from, e.to+1, sorted_a[md], 0, 0, N, segment_data_tree);
      if (c >= e.k) ub = md;
      else lb = md;
    }
    std::cout << sorted_a[ub] << '\n';
  }
}
int main(int argc, char** argv) {
  const int n {7};
  const int m {3};
  const std::vector<int> a{1, 5, 2, 6, 3, 7, 4};
  const std::vector<query> que{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
  answer(n, m, a, que);
}
