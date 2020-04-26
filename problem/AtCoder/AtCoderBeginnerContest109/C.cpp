#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF
constexpr int INTINF {1000000000};//int = 2*INTINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T&& y) {
  x=std::max(x,y);
}
template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T&& y) {
  x=std::min(x,y);
}
template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, X;
  cin >> N;
  vector<int> D(N+1);
  rep(i, N+1) cin >> D[i];

  std::sort(D.begin(), D.end());
  vector<int> A(N);
  rep(i, N) {
    A[i] = D[i+1] - D[i];
  }
  std::sort(A.begin(), A.end());
  vector<int> prime;
  for (int c = 2, tmp = A[0];c <= tmp;++c) {
    if (tmp % c == 0) {
      prime.push_back(c);
      tmp /= c;
      --c;
    }
  }
  ull answer {1};
  rep(i, prime.size()) {
    bool is_ok = true;
    for (const auto& e : A) {
      if (e % prime[i] != 0) {
        is_ok = false;
        break;
      }
    }
    if (is_ok == true) {
      answer *= prime[i];
    }
  }
  cout << answer << '\n';
}
