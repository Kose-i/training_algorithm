#include <iostream>
#include <vector>

struct Node{
  int x, y;
  int c;
};

void answer(const std::vector<Node>& node_list, const std::vector<std::vector<int>>& node_tree, std::vector<int>& roots_node, const int& N, const int& S, const int& K) {
  std::vector<std::vector<int>> node_table(N, std::vector<int>(N, 0));
  for (auto i = 0;i < S;++i) {
    for (auto j = 0;j < K-1;++j) {
      if (node_table)
    }
  }
}
int main(int argc, char** argv) {
  int N, S, K;
  std::cin >> N >> S >> K;
  std::vector<Node> node_list(N);
  for (auto& e : node_list) {
    std::cin >> e.x >> e.y >> e.c;
  }
  std::vector<std::vector<int>> node_tree(S, std::vector<int>(K-1));
  for (auto& e : node_tree) {
    for (auto& f : e) {
      std::cin >> f;
    }
  }
  std::vector<int> roots_node(S, 0);
  answer(node_list, node_tree, roots_node, N, S, K);
}
