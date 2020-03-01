#include <iostream>
#include <vector>

#define rep(i,n) for(int i = 0;i < (n);++i)
using ll = long long;

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::cout << ((N/2+((N%2)?1:0))) << '\n';
}
