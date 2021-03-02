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

int calc_dish(const std::vector<int>& dish_table, const std::vector<int>& c, const std::vector<int>& d) {
  int ans {};
  for (auto i = 0;i < c.size();++i) {
    if (dish_table[c[i]]>0 && dish_table[d[i]]>0) ++ans;
  }
  return ans;
}
int all_search(vector<int> dish_table, int idx, int end_idx, const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c, const std::vector<int>& d) {
  if (idx==end_idx) return calc_dish(dish_table, c, d);
  //cout << idx << ' ';
  ++dish_table[a[idx]];
  int ans = all_search(dish_table, idx+1,end_idx, a, b, c, d);
  --dish_table[a[idx]];
  ++dish_table[b[idx]];
  ans= max(all_search(dish_table, idx+1, end_idx, a, b, c, d), ans);
  --dish_table[b[idx]];
  return ans;
}
int max_all_search(const int& n, const int& m, const int& k, const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c, const std::vector<int>& d) {
  vector<int> dish_table(n+1,0);
  return all_search(dish_table, 0, k, a, b, c, d);
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  vector<int> b(m);
  rep(i, m) cin >> a[i] >> b[i];
  int k;
  cin >> k;
  vector<int> c(k);
  vector<int> d(k);
  rep(i, k) cin >> c[i] >> d[i];

  cout << max_all_search(n, m, k, c, d, a, b) << '\n';
}
