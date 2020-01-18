#include <iostream>
#include <vector>

struct Pair {
  int num;
  int flip_cnt;
};

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}

bool is_sorted(const std::vector<Pair>& t, const std::vector<int>& A, const std::vector<int>& B) {
  int tmp_A {};
  for (const auto& e : t) {
    if (e.flip_cnt % 2 == 1) {
      if (B[e.num] < tmp_A) {
        return false;
      }
      tmp_A = B[e.num];
    } else {
      if (A[e.num] < tmp_A) {
        return false;
      }
      tmp_A = A[e.num];
    }
  }
  return true;
}
void swap(std::vector<Pair>& t, const int& num_1, const int& num_2) {
  Pair t_cp = t[num_1];
  t[num_1] = t[num_2];
  t[num_2] = t_cp;
  ++t[num_1].flip_cnt;
  ++t[num_2].flip_cnt;
}
void print(const std::vector<Pair>& t, const std::vector<int>& A, const std::vector<int>& B) {
  bool is_space = false;
  for (const auto& e : t) {
    if (is_space) {
      std::cout << ' ';
    }
    is_space = true;
    if (e.flip_cnt % 2 == 1) {
      std::cout << B[e.num];
    } else {
      std::cout << A[e.num];
    }
  }
  std::cout << '\n';
}

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  std::vector<int> B(N);
  for (auto& e : A) std::cin >> e;
  for (auto& e : B) std::cin >> e;
  std::vector<Pair> C(N,{0, 0});
  for (auto i = 0;i < N;++i) {
    C[i].num = i;
  }
  if (is_sorted(C, A, B)) {
    std::cout << '0' << '\n';
    return 0;
  }
  int min_cnt {N*N+1};
  int mul_N {1};
  for (auto i = 1;i <= N;++i) {
    mul_N *= i;
  }
  std::vector<std::vector<Pair>> C_vec(mul_N);
  for (auto& C_tmp : C_vec) {
    flip_calculate(C_tmp);
    int sum_flip {};
    for (auto& e : tmp_cp) {sum_flip ;= e.flip_cnt;}
    if (min_cnt < sum_flip) continue;
    if (is_sorted(C_tmp, A, B)) {
      min_cnt = sum_flip;
    }
  }
  if (min_cnt > N*N) {
    std::cout << "-1" << '\n';
  } else {
    std::cout << min_cnt << '\n';
  }
}
