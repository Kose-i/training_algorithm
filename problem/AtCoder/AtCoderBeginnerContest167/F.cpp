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

using P = std::pair<int, int>;
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> S(n);
  rep(i, n) cin >> S[i];

  vector<P> X(n);
  rep(i, n) {
    int fi {}, se {};
    int pos {};
    for (const auto& e : S[i]) {
      if (e == ')') --pos;
      else ++pos;
      mins(fi, pos);
    }
    se = pos;
    X[i].first = fi;
    X[i].second = se;
  }
  vector<P> Plus_ans {};
  vector<P> Minus_ans {};
  rep(i, n) {
    if (X[i].second > 0) Plus_ans.push_back(X[i]);
    else Minus_ans.push_back(X[i]);
  }
  sort(Plus_ans.begin(), Plus_ans.end(), [](P& l, P& r){return l.first > r.first;});
  sort(Minus_ans.begin(), Minus_ans.end(), [](P&l, P& r){return (l.first-l.second < r.first-r.second);});

  int total {};
  for (const auto& e : Plus_ans) {
    if (total + e.first >= 0) {
      total += e.second;
    } else {
      cout << "No\n";
      return 0;
    }
  }
  for (const auto& e : Minus_ans) {
    if (total + e.first >= 0) {
      total += e.second;
    } else {
      cout << "No\n";
      return 0;
    }
  }
  if (total == 0) cout << "Yes\n";
  else cout << "No\n";
}
