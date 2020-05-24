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

struct query{
  int a, b, c, d;
};

int get_value(const int& X_size, const vector<query>& X, const vector<int>& A) {
  int ans {};
  rep(i, X_size) {
    if (A[X[i].b] - A[X[i].a] == X[i].c) {
      ans += X[i].d;
    }
  }
  return ans;
}

int check(const int& index, const int& n, const int& M, const int& X_size, const int& now_value, const vector<query>& X, vector<int> A) {
  if (index == n) {
    return get_value(X_size, X, A);
  }
  int ans {};
  srep(i, now_value, M+1) {
    A[index] = i;
    maxs(ans, check(index+1, n, M, X_size, i, X, A));
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M, Q;
  cin >> N >> M >> Q;
  vector<query> X(Q);
  rep(i, Q) {
    cin >> X[i].a >> X[i].b >> X[i].c >> X[i].d;
    --X[i].a;
    --X[i].b;
  }

  vector<int> A(N, 1);
  int ans = check(0, N, M, Q, 1,X, A);
  cout << ans << '\n';
}
