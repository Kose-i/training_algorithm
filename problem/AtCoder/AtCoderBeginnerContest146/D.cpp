#include <algorithm>
#include <iostream>
#include <vector>

struct Path {
  int from, to;
  int color;
};

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<Path> A(N-1);
  for (auto& e : A) {
    std::cin >> e.from >> e.to;
    --e.from;
    --e.to;
  }
  std::vector<std::vector<int>> Edge_Num(N, std::vector<int>());
  int K {1};
  for (auto& e : A) {
    bool is_find = false;
    for (auto i = 1;i < K;++i) {
      if (std::find(Edge_Num[e.from].begin(), Edge_Num[e.from].end(), i)==Edge_Num[e.from].end() && std::find(Edge_Num[e.to].begin(), Edge_Num[e.to].end(), i)==Edge_Num[e.to].end()) {
        Edge_Num[e.from].push_back(i);
        Edge_Num[e.to].push_back(i);
        e.color = i;
        is_find = true;
        break;
      }
    }
    if (is_find == false) {
        ++K;
        Edge_Num[e.from].push_back(K);
        Edge_Num[e.to].push_back(K);
        e.color = K;
    }
  }
  std::cout << K << '\n';
  for (auto& e : A) {
    std::cout << e.color << '\n';
  }
}
