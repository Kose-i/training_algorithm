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


constexpr int contest_num {26};

void calc_satisfy(const vector<vector<ll>>& S, const vector<ll>& C, const vector<int>& order, const int& D) {
  ll answer {};
  vector<int> fin_day(contest_num, -1);
  rep(i, D) {
    answer += S[i][order[i]-1];
    fin_day[order[i]-1] = i;
    rep(j, contest_num) {
      answer -= C[j]*(i-fin_day[j]);
    }
    //cout << answer << '\n';
  }
  cout << answer << '\n';
  //return answer;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int D;
  cin >> D;
  vector<ll> c(contest_num);
  rep(i, contest_num) cin >> c[i];
  vector<vector<ll>> s(D, vector<ll>(contest_num));
  rep(i, D) {
    rep(j, contest_num) {
      cin >> s[i][j];
    }
  }
  vector<int> order(D);
  rep(i, D) cin >> order[i];
  int M;
  cin >> M;
  vector<std::pair<int, int>> query(M);
  rep(i, M) cin >> query[i].first >> query[i].second;
  rep(i, M) {
    order[query[i].first-1] = query[i].second;
    calc_satisfy(s, c, order, D);
  }
  //rep(i, D) cout << order[i] << ' ';
  //calc_satisfy(s, c, order, D);
}
