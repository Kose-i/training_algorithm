#include <iostream>
#include <vector>

#define rep(i,n) for(int i = 0;i < (n);++i)
using ll = long long;

struct P {
  int keta;
  int num;
};

int main(int argc, char** argv) {
  int N, M;
  std::cin >> N >> M;
  std::vector<P> c(M);
  rep(i,M) std::cin >> c[i].keta >> c[i].num;
  std::vector<char> Number(N, 'a');

  bool is_error = false;
  rep(i, M) {
    if (Number[c[i].keta - 1] == 'a') {
      Number[c[i].keta - 1] = c[i].num + '0';
    } else if (Number[c[i].keta - 1] != c[i].num+'0') {
      is_error = true;
      break;
    }
  }
  if (is_error == true) {
    std::cout << "-1\n";
  } else if (N == 1) {
    if (Number[0] != 'a') {
      std::cout << Number[0];
    } else {
      std::cout << "0\n";
    }
  } else if (Number[0] == '0') {
    std::cout << "-1\n";
  } else {
    rep(i, N) {
      if (Number[i] == 'a' && i == 0) std::cout << '1';
      else if (Number[i] == 'a') std::cout << '0';
      else std::cout << Number[i];
    }
  }
}
