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

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

struct P {
  int a, b;
};

constexpr int mod_target{1000000000+7};
int f(vector<vector<char>>& table, vector<char>& stay, int now_p, const int& N) {
  stay[now_p] = 0;
  int answer {};
  int cnt {};
  rep(i, N) {
    if (table[now_p][i] == 1 && stay[i] == 1) {
      ++cnt;
      answer += f(table, stay, i, N);
      answer %= mod_target;
      cnt %= mod_target;
    }
  }
  if (cnt == 0) return 1;
  return answer*cnt % mod_target;
}

int main() {
  int N;
  cin >> N;
  vector<P> X(N-1);
  rep(i, N-1) cin >> X[i].a >> X[i].b;
  vector<vector<char>> Table(N, vector<char>(N, 0));

  rep(i, N-1) {
    Table[X[i].a-1][X[i].b-1] = 1;
    Table[X[i].b-1][X[i].a-1] = 1;
  }
  rep(i, N) {
    vector<char> c(N, 1);
    int answer = f(Table, c, i, N);
    cout << answer%mod_target << '\n';
  }
}
