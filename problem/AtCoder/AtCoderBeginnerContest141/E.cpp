#include <iostream>
#include <string>

bool is_same(const std::string& S, const int& l1, const int& l2, const int& len) {
  for (auto i = 0;i < len;++i) {
    if (S[l1+i] != S[l2+i]) return false;
  }
  return true;
}
bool is_ok(const std::string& S, const int& S_size, const int& len) {
  for (auto i = 0;i < S_size-2*len;++i) {
    for (auto j = i+len;j <= S_size-len;++j) {
      if (is_same(S, i, j, len)) return true;
    }
  }
  return false;
}

int main() {
  int N;
  std::string S;
  std::cin >> N >> S;
  int S_size = S.size();
  int left = 0, right = N;
  for (int len = (left+right)/2;left+1<right;) {
    if (is_ok(S, S_size, len)) left = len;
    else right = len;
    len = (left + right)/2;
  }
  std::cout << left << '\n';
}
