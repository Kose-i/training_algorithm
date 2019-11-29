#include <iostream>
#include <vector>

namespace prob54{
  unsigned search(const std::vector<unsigned>& prime_box, const int& count, unsigned left, unsigned right) {
    while (left + 1 < right) {
      unsigned mid = (left + right)/2;
      unsigned cnt = 1;
      unsigned weight {};
      for (const auto& prime : prime_box) {
        if (weight + prime < mid) {
          weight += prime;
        } else {
          weight = prime;
          ++cnt;
        }
      }
      if (count >= cnt) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return left;
  }
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
  unsigned answer(const int& count, const int& prime_max) {
    std::vector<unsigned> prime_box = make_prime_vec(prime_max);
    unsigned sum_prime {};
    for (const auto& e : prime_box) {
      sum_prime += e;
    }
    return search(prime_box, count, 0, sum_prime);
  }
}

int main(int argc, char** argv) {
  const int count {500};
  const int prime_max {10000};
  std::cout << prob54::answer(count, prime_max) << '\n';
}
