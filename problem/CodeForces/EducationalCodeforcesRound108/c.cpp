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

int sum_array(const std::vector<std::vector<std::vector<int>>>& array, const int& n) {
  int sum {};
  for (auto i = 0;i < array.size();++i) {
    for (auto j = 0;j < (array[i][0].size()/n)*n;++j) {
      sum += array[i][0][j];
    }
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int times_n; cin >> times_n;

  std::vector<int> n(times_n);
  std::vector<std::vector<int>> groups(times_n);
  std::vector<std::vector<int>> power_member(times_n);
  rep(i, times_n) {
    cin >> n[i];
    std::vector<int> g(n[i]);
    rep(j, n[i]) cin >> g[j];
    std::vector<int> p(n[i]);
    rep(j, n[i]) cin >> p[j];
    groups[i] = g;
    power_member[i] = p;
  }

  rep(i, times_n) {
    int groups_num {};
    std::map<int, int> mp;
    for (const auto& e : groups[i]) if (mp.find(e) == mp.end()) mp[e] = groups_num++;
    std::vector<std::vector<int>> member(groups_num);
    rep(j, n[i]) {
      member[mp[groups[i][j]]].push_back(power_member[i][j]);
    }
    rep(j, groups_num) {
      std::sort(member[j].rbegin(), member[j].rend());
      member[j].insert(member[j].begin(), 0);
    }
    rep(j, groups_num) {
      srep(k, 1, member[j].size()) {
        member[j][k] += member[j][k-1];
      }
    }
    bool isfirst {true};
    srep(j, 1, n[i]+1) {
      int ans {};
      rep(k, groups_num) {
        int idx = ((member[k].size()-1)/j)*j;
        if (idx < 0 || member[k].size()<=idx) idx = 0;
        ans += member[k][idx];
      }
      if(!isfirst) cout << ' ';
      isfirst = false;
      cout << ans;
    }
    cout << '\n';
  }
}