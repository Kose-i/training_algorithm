#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned long max(unsigned long a, unsigned long b) {
  return (a > b)?a:b;
}

unsigned long max_score(const std::vector<unsigned long>& vec) {
  unsigned long ans {};
  for (const auto& e : vec) ans = max(ans, e);
  return ans;
}

bool is_ok(std::vector<unsigned long> A, std::vector<unsigned long> F, unsigned long long K, unsigned long long time, const unsigned long& N) {
  std::sort(A.begin(), A.end());
  std::sort(F.begin(), F.end(), std::greater<unsigned long>());
  for (auto i = 0;i < N;++i) {
    while (A[i]*F[i] > time) {
      if (K==0) return false;
      --K;
      --A[i];
    }
  }
  return true;
}

int main(int argc, char** argv) {
  unsigned long N;
  std::cin >> N;
  unsigned long long K;
  std::cin >> K;
  std::vector<unsigned long> A(N);
  for (auto& e : A) std::cin >> e;
  std::vector<unsigned long> F(N);
  for (auto& e : F) std::cin >> e;
  unsigned long long right_time = max_score(A)*max_score(F);
  unsigned long long left_time {};
  for (;right_time - left_time > 1;) {
    unsigned long long mid_time = (right_time + left_time)/2;
    if (is_ok(A, F, K, mid_time, N)) {
      right_time = mid_time;
    } else {
      left_time = mid_time;
    }
  }
  if (is_ok(A, F, K, left_time, N)) {
    std::cout << left_time << '\n';
  } else {
    std::cout << right_time << '\n';
  }
}
