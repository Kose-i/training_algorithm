#include <iostream>
#include <vector>

#include <string>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  std::string S;
  std::cin >> S;
  int S_size = S.size();
  for (auto i = 0;i < S_size;++i) {
    if (S[i] == 'a' && i != S_size-1 && S[i+1] == 'o') {
      S[i] = 'k';
      S[i+1] = 'i';
      ++i;
    }
  }
  std::cout << S << '\n';
}
