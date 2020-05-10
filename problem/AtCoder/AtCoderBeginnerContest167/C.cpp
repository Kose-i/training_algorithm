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

ll answer(const int& idx, const int& n, const int& m, const ll& now_cost, const vector<ll>& Cost, const vector<vector<ll>>& A, const ll& X , vector<ll> judge) {
  if (idx == n) {
    rep(i, m) {
      if (judge[i] < X) return -1;
    }
    return now_cost;
  }
  ll answer_on, answer_off;
  {
    vector<ll> new_on_judge(m, 0);
    rep(i, m) {
      new_on_judge[i] = judge[i] + A[idx][i];
    }
    answer_on = answer(idx+1, n, m, now_cost + Cost[idx], Cost, A, X, new_on_judge);
  }
  {
    answer_off = answer(idx+1, n, m, now_cost, Cost, A, X, judge);
  }
  if (answer_on == -1) return answer_off;
  else if (answer_off == -1) return answer_on;
  if (answer_on < answer_off) return answer_on;
  else return answer_off;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M;
  ll X;
  cin >> N >> M >> X;
  vector<ll> Cost(N);
  vector<vector<ll>> A(N, vector<ll>(M));
  rep(i, N) {
    cin >> Cost[i];
    rep(j, M) {
      cin >> A[i][j];
    }
  }
  vector<ll> judge(M, 0);
  cout << answer(0, N, M, 0, Cost, A, X, judge) << '\n';
}
