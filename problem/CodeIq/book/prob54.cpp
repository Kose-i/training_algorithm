#include <iostream>
#include <vector>

namespace prob54{
  std::vector<unsigned> make_prime_vec(const int& prime_max) {
    std::vector<unsigned> prime_box;
    for (auto i = 2;i <= prime_max;++i) {
      bool flag {true};
      for(const auto& e : prime_box) {
        if (i % e == 0) {
          flag = false;
          break;
        }
        if (e*e > i) break;
      }
      if (flag == true) prime_box.push_back(i);
    }
    return prime_box;
  }
  unsigned search(const int& n, const int& i, std::vector<std::vector<unsigned>>& memo, const std::vector<unsigned>& prime_box) {
    if (memo[n][i]) return memo[n][i];
    if (i == prime_box.size()) return (n==0)?1:0;
    int use = prime_box[i];
    unsigned cnt {};
    cnt += search(n + use, i+1, memo, prime_box);
    cnt += search( ((n-use>0)?(n-use):-(n-use)) , i+1, memo, prime_box);
    cnt += search(n, i+1, memo, prime_box);
    return memo[n][i] = cnt;
  }
  unsigned answer(const int& M, const int& N) {
    std::vector<unsigned> prime_box = make_prime_vec(M);
    unsigned prime_size = prime_box.size();
    unsigned sum_primes {};
    for (const auto& e : prime_box) {
      sum_primes += e;
    }
    std::vector<std::vector<unsigned>> memo(sum_primes+N+1, std::vector<unsigned>(prime_size+1, 0));
    return search(N, 0, memo, prime_box);
  }
}

int main(int argc, char** argv) {
  const int m {50};
  const int n {5};
  std::cout << prob54::answer(m, n) << '\n';
}
