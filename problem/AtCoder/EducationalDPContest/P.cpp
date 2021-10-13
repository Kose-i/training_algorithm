#include <iostream>
#include <vector>
#include <utility>

using ll = long long;
using Pair = std::pair<ll,ll>;

using namespace std;

#define rep(i,n) for(int i = 0;i < (n);++i)
constexpr ll ll_mod {1000000000+7};

//O(2 * n)
Pair search(const vector<vector<int>>& path, const int& parent, const int& child) {
    Pair ans; ans.first = 1; ans.second = 1;
    for (const auto& e : path[child]) {
        if (e == parent) continue;
        Pair tmp = search(path, child, e);
        ans.first *= (tmp.first + tmp.second);
        ans.second *= tmp.first;

        ans.first %= ll_mod;
        ans.second%= ll_mod;
    }
    return ans;
}
int main(int argc, char** argv) {
  int n;
  std::cin >> n;
  vector<Pair> a(n-1); 
  rep(i,n-1) cin >> a[i].first >> a[i].second;

  vector<vector<int>> path(n);
  rep(i, n-1) {
    path[a[i].first - 1].push_back(a[i].second-1);
    path[a[i].second- 1].push_back(a[i].first -1);
  }
  Pair ans = search(path, 0, 0);
  cout << (ans.first + ans.second)%ll_mod << '\n';
}
