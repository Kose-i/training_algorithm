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
struct Node {
    int idx;
    int win_cnt;
};
bool operator<(Node l, Node r) {
    return ((l.win_cnt == r.win_cnt)?(l.idx < r.idx) : (l.win_cnt > r.win_cnt));
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  n *= 2;
  vector<vector<int>> a(n, vector<int>(m));
  const std::vector<std::vector<int>> table {{0,1,-1 }, {-1, 0,1}, {1,-1, 0}};

  for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
    char c;
    cin >> c;
    if (c == 'G') a[i][j] = 0;
    else if (c == 'C') a[i][j] = 1;
    else a[i][j] = 2;
  }

  vector<Node> ans(n);
  for (int i=0;i<n;++i) {
    ans[i].idx = i+1;
    ans[i].win_cnt = 0;
  }
  for (int i=0;i<m;++i) {
    for (int j=0;j<n;j += 2) {
        if (table[a[ans[j].idx-1][i]][a[ans[j+1].idx-1][i]] == 1) {
            ++ans[j].win_cnt;
        } else if (table[a[ans[j].idx-1][i]][a[ans[j+1].idx-1][i]] == -1) {
            ++ans[j+1].win_cnt;
        }
    }
    std::sort(ans.begin(), ans.end());
  }
  for (int i=0;i<n;++i) cout << ans[i].idx << '\n';
}
