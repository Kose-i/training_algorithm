#include <iostream>
#include <vector>

struct query{
  bool is_add = false;
  int l, r;
  int x;
};

void add_BIT(const int& left, const int& right, const int& x, std::vector<int>& BIT_tree) {
  int i = left;
  while (i < right) {
    BIT_tree[i] += x;
    //i += (i &(-i));
    i += 1;
  }
}

int sum_BIT(const int& left, const int& right, const std::vector<int>& BIT_tree) {
  return 1;
}
void print_BIT(const std::vector<int>& BIT_tree) {
  int tree_size = BIT_tree.size();
  for (auto i = 0;i < tree_size;++i) {
    int c {BIT_tree[i]};
    if (i % 2 != 0) {
      c -= BIT_tree[i/2];
      c -= BIT_tree[i -2];
    }
    std::cout << c << ' ';
  }
  std::cout << '\n';
}
void answer(const int& vec_size, const std::vector<int>& vec, const std::vector<query>& q) {
  std::cout << "answer\n";
  std::vector<int> BIT_tree(vec_size, 0);
  for (auto i = 0;i < vec_size;++i) {
    add_BIT(i, i+1, vec[i], BIT_tree);
  }
  print_BIT(BIT_tree);
  return;
  for (const auto& q_elem : q) {
    if (q_elem.is_add == true ) {
      add_BIT(q_elem.l, q_elem.r, q_elem.x, BIT_tree);
    } else {
      int sum = sum_BIT(q_elem.l, q_elem.r, BIT_tree);
      std::cout << sum << '\n';
    }
  }
  print_BIT(BIT_tree);
}
int main(int argc, char** argv) {
  const int N {8};
  std::vector<int> vec{5, 3, 7, 9, 6, 4, 1, 2};
  std::vector<query> q;
  q.push_back({true, 0, 5, 1});
  q.push_back({false, 0, 7, 0});
  answer(N, vec, q);
}
