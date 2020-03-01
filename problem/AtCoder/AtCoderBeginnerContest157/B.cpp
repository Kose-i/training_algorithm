#include <iostream>
#include <vector>

#define rep(i,n) for(int i = 0;i < (n);++i)
using ll = long long;

bool is_same(int a, int b, int c) {
  return (a==b)&&(b==c);
}

bool is_bingo(const std::vector<int>& c) {
  rep(i,3)
  if (is_same(c[3*i+0], c[3*i+1], c[3*i+2])) return true;

  rep(i,3)
  if (is_same(c[i+0], c[i+3], c[i+6])) return true;

  if (is_same(c[0], c[4], c[8])) return true;
  if (is_same(c[6], c[4], c[2])) return true;
  return false;
}

int main(int argc, char** argv) {
  std::vector<int> card(9);
  rep(i,9) std::cin >> card[i];
  int N;
  std::cin >> N;
  std::vector<int> b(N);
  rep(i, N) std::cin >> b[i];
  rep(i,N) {
    rep(j,9) {
      if (card[j] == b[i]) {
        card[j] = 0;
        break;
      }
    }
  }
  if (is_bingo(card)) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
