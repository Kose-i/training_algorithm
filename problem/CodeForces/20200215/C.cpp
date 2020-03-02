#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

int main(int argc, char** argv) {
  ll quize_cnt {};
  std::cin >> quize_cnt;
  std::vector<ll> n(quize_cnt);
  std::vector<ll> m(quize_cnt);
  std::vector<std::vector<ll>> t;
  std::vector<std::vector<ll>> l;
  std::vector<std::vector<ll>> h;
  rep(i, quize_cnt) {
    std::cin >> n[i] >> m[i];
    std::vector<ll> t_tmp(n[i]);
    std::vector<ll> l_tmp(n[i]);
    std::vector<ll> h_tmp(n[i]);
    rep(j, n[i]) std::cin >> t_tmp[j] >> l_tmp[j] >> h_tmp[j];
    t.push_back(t_tmp);
    l.push_back(l_tmp);
    h.push_back(h_tmp);
  }
  rep(i, quize_cnt) {
    ll lowest  = m[i];
    ll highest = m[i];
    bool is_no = false;
    rep(j, n[j]) {
      if (j == 0) {
        lowest  -= t[i][j];
        highest += t[i][j];
      } else {
        lowest  -= (t[i][j] - t[i][j-1]);
        highest += (t[i][j] - t[i][j-1]);
      }
      if (lowest > h[i][j] || highest < l[i][j]) {
        is_no = true;
        break;
      }
      if (lowest  < l[i][j]) lowest  = l[i][j];
      if (highest > h[i][j]) highest = h[i][j];
    }
    if (is_no == true) std::cout << "NO\n";
    else std::cout << "YES\n";
  }
}
