#include <iostream>
#include <vector>

struct Prime_Factor{
  int prime_num;
  int prime_count;
};

std::vector<int> prime_box;
void prime_make(const int& N) {
  std::vector<char> is_prime(N, 1);
  is_prime[0] = 0; is_prime[1] = 0;
  for (auto i = 2;i <= N;++i) {
    if (is_prime[i] == 1) {
      for (auto j = i+i;j <= N;j += i) {
        is_prime[j] = 0;
      }
    }
  }
  for (auto i = 2;i <= N;++i) {
    if (is_prime[i] == 1) prime_box.push_back(i);
  }
}
std::vector<Prime_Factor> make_factor(int n) {
  std::vector<Prime_Factor> ans;
  for (auto i = 0;n!=1 && i!=prime_box_end;++i) {
    if (n % prime_box[i] == 0) {
      Prime_Factor tmp
      tmp.prime_num = prime_box[i];
      tmp.prime_count = 0;
      for (;n % prime_box[i] == 0;n /= prime_box[i]) {
        ++tmp.prime_count;
      }
      ans.push_back(tmp);
    }
  }
  return ans;
}

int main(int argc, char** argv) {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(N);
  for (auto& e : A) std::cin >> e;
  std::vector<std::vector<Prime_Factor>> B(N);
  for (auto i = 0;i < N;++i) {
    B[i] = make_factor(A[i]);
  }

  std::vector<Prime_Factor> max_factor {};
  for (const auto& e : B) {
    for (const auto& f : e) {
      //TODO
    }
  }
  long max_num {1};
  for (const auto& e : max_factor) {
    for (auto i = 0;i < e.prime_count;++i) {
      max_num *= e.prime_num;
    }
  }
  std::cout << M / max_num << '\n';
}
