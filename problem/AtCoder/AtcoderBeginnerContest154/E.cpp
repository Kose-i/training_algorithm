#include <iostream>

unsigned long long answer(const int& saijoui_num, const std::string& S, const int& K, const int& keta) {
  if (K == 1) {
    return ((S[saijoui_num] - '0') + 9*(keta - saijoui_num -1));
  } else if (K == 2) {
    if (keta < 2) return 0;
    int n = keta - saijoui_num - 1;
    unsigned long long t {};
    t += 27*(n-1)*n*(n+1)/4;
    t += (S[saijoui_num]-'0'-1)*9*(keta - 1);
    t += answer(saijoui_num + 1, S, K-1, keta);
    return t;
  } else { // K==3
    if (keta < 3) return 0;
    unsigned long long n = keta - 1;
    unsigned long long t = (n-2)*(n-1)*n*(n+1)*81/8;
    t += (S[saijoui_num]-'0'-1)*81*(n-1)*n/2;
    t += answer(saijoui_num+1, S, K-1, keta);
    return t;
  }
}
int main(int argc, char** argv) {
  std::string N;
  int K;
  std::cin >> N >> K;

  std::cout << answer(0, N, K, N.size()) << '\n';
}
