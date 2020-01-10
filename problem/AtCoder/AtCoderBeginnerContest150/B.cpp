#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int N;
  std::string S;
  std::cin >> N >> S;
  int cnt {};
  for (auto i = 0;i < N-2;++i) {
    if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') ++cnt;
  }
  std::cout << cnt << '\n';
}
