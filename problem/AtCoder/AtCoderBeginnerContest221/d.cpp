#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pair = std::pair<int, int>;

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

  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (int i=0;i<n;++i) {
    cin >> a[i] >> b[i];
    b[i] = a[i] + b[i];
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  vector<ll> ans(n+1, 0);

  int a_idx {};
  int b_idx {};
  int now_players {};
  ll now_days {};
  map<ll, int> mp;
  for (int i=0;i<n;++i) {
    mp[a[i]]++;
    mp[b[i]]--;
  }

  for (const auto& e : mp) {
    ans[now_players] += e.first - now_days - 1;
    now_days = e.first - 1;
    now_players += e.second;
  }
  bool is_first {true};
  for (int i=1;i<=n;++i) {
    if (!is_first) cout << ' ';
    cout << ans[i];
    is_first = false;
  }
  cout << '\n';
}