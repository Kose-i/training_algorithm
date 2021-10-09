#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <utility>
#include <queue>

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
struct Node {
    int idx;
    vector<int> path;
};
bool operator<(Node l, Node r) {
    return l.path.size()<r.path.size();
}
ll mod_ll {998244353};
ll ncr(int n, int r) {
    ll ans {1};
    for (int i=0;i<r;++i) {
        ans *= (n-r);
        ans %= mod_ll;
    }
    for (int i=r;1<=i;--i) {
        (ans+mod_ll) /= i;
        ans %= mod_ll;
    }
    return ans;
}

ll dfs_helper(map<int, int>& mp, map<int, int>::iterator& mp_it, int k) {
    ll ans {};
    Pair tmp = *mp_it;
    if (mp_it == mp.end() && k == 0) {
        return 1;
    } else if (mp_it == mp.end()) {
        return 0;
    }

    for (int i=0; i < tmp.second;++i) {
        ans += ncr(tmp.second, i) * dfs_helper(mp, mp_it+1, k-i*tmp.first+(tmp.second-i)*tmp.first);
        ans %= mod_ll;
    }
    return ans;
}

ll dfs(map<int, int>& mp, int k) {
    ll mod_ll {998244353};
    ll tmp {1};
    for (int i=0;i<mp[0];++i) {
        tmp *= 2;
        tmp %= mod_ll;
    }
    return (tmp * dfs_helper(mp, std::next(mp.begin()), 1, k)) % mod_ll;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m);
  for (int i=0;i<m;++i) {
    cin >> a[i];
    --a[i];
  }
  map<int, vector<int>> mp;
  for (int i=0;i<n-1;++i) {
    int u, v;
    cin >> u >> v;
    mp[u-1].push_back(v-1);
    mp[v-1].push_back(u-1);
  }

  vector<vector<vector<int>>> minimum_path(n, vector<vector<int>>(n, vector<int>()));

  for (int i=0;i<n;++i) {
    std::queue<Node> next_pos;
    Node tmp;
    tmp.idx = i;
    next_pos.push(tmp);
    vector<char> is_find(n, 0);
    is_find[i] = 1;
    for (;!next_pos.empty();) {
        Node next = next_pos.front(); next_pos.pop();
        for (int& e : mp[next.idx]) {
            if (is_find[e] == 0) {
                tmp = next;
                tmp.idx = e;
                tmp.path.push_back(e);
                next_pos.push(tmp);
            }
        }
        is_find[next.idx] = 1;
        minimum_path[i][next.idx] = next.path;
    }
  }

  map<Pair, int> path_cnt;
  Pair path_pair {a[0], a[0]};
  int now_pos {a[0]};
  for (int i=1;i<m;++i) {
    for (int e : minimum_path[now_pos][a[i]]) {
        path_pair.second = e;
        {
            Pair tmp;
            if (path_pair.first < path_pair.second) {
                tmp = path_pair;
            } else {
                tmp.first = path_pair.second;
                tmp.second = path_pair.first;
            }
            ++path_cnt[tmp];
        }
        path_pair.first = e;
    }
    now_pos = a[i];
  }
  map<int, int> weights;
  for (const auto& e : path_cnt) {
    ++weights[e.second];
  }
  {
    int tmp {n-1};
    for (auto& e : weights) tmp -= e.second;
    weights[0] = tmp;
  }
  //for (auto& e : weights) cout << e.first << '-' << e.second << '\n';
  cout << dfs(weights, k) << '\n';
}
