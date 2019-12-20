#include <iostream>
#include <vector>

struct query{
  bool is_add = false;
  int l, r;
  int x;
};

void add_BIT(const int& left, const int& right, const int& x, std::vector<int>& BIT_tree) {
  int BIT_tree_size = BIT_tree.size();
  for (auto l = left;l < right;++l) {
    auto i = l;
    while (i < BIT_tree_size) {
      BIT_tree[i] += x;
      i += (i &(-i));
    }
  }
}

int sum_BIT(const int& left, const int& right, const std::vector<int>& BIT_tree) {
  int s {};
  int i {right};
  while (i > 0) {
    s += BIT_tree[i];
    i -= i&(-i);
  }
  i = left;
  while (i > 0) {
    s -= BIT_tree[i];
    i -= i&(-i);
  }
  return s;
}
void print_BIT(const std::vector<int>& BIT_tree) {
  int tree_size = BIT_tree.size();
  for (auto i = 0;i < tree_size;++i) {
    int c {sum_BIT(i, i+1, BIT_tree)};
    std::cout << c << ' ';
  }
  std::cout << '\n';
}
void answer(const int& vec_size, const std::vector<int>& vec, const std::vector<query>& q) {
  std::vector<int> BIT_tree(vec_size+1, 0);
  for (auto i = 0;i < vec_size;++i) {
    add_BIT(i+1, i+2, vec[i], BIT_tree);
  }
  for (const auto& q_elem : q) {
    if (q_elem.is_add == true ) {
      add_BIT(q_elem.l+1, q_elem.r+1, q_elem.x, BIT_tree);
    } else {
      int sum = sum_BIT(q_elem.l+1, q_elem.r+1, BIT_tree);
      std::cout << sum << '\n';
    }
  }
}
int main(int argc, char** argv) {
  const int N {8};
  std::vector<int> vec{5, 3, 7, 9, 6, 4, 1, 2};
  std::vector<query> q;
  q.push_back({true, 0, 5, 1});
  q.push_back({false, 0, 7, 0});
  answer(N, vec, q);
}
