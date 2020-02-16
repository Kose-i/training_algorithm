#include <iostream>
#include <vector>

using ull = unsigned long long;
using ll = long long;

int main(int argc, char** argv) {
  std::string N;
  std::cin >> N;
  ull N_size = N.size();
  std::vector<ull> vec(10);
  bool kuriagari = false;
  for (ll i = N_size-1;i >= 0;--i) {
    if (kuriagari == true) {
      if (N[i] >= '5') {
        ++vec['9' - N[i]];
      } else {
        kuriagari = false;
        ++vec[N[i] - '0' + 1];
      }
    } else if (N[i] < '5') {
      ++vec[N[i]-'0'];
    } else {
      kuriagari = true;
      ++vec['9' - N[i] + 1];
    }
  }
  ull answer {};
  if (kuriagari == true) {
    ++answer;
  }
  for (auto i = 0;i <= 9;++i) {
    answer += vec[i]*i;
  }
  std::cout << answer << '\n';
}
