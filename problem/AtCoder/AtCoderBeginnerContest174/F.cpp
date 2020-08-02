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

using P = std::pair<ull, ull>;
bool operator<(const P& l, const P& r) {
  return l.first < r.first;
}

vector<P> add(const vector<P>& l, const vector<P>& r) {
  auto l_size = l.size();
  auto r_size = r.size();
  auto r_index = 0;
  vector<P> ans;
  for (auto l_index = 0;l_index < l_size;++l_index) {
    if (r_index == r_size) {
      P tmp = l[l_index];
      ans.push_back(tmp);
    } else if (l[l_index] < r[r_index]) {
      P tmp = l[l_index];
      ans.push_back(tmp);
    } else if (l[l_index] == r[r_index]) {
      P tmp = l[l_index];
      tmp.second += r[r_index].second;
      ans.push_back(tmp);
      ++r_index;
    } else {
      P tmp = r[r_index];
      ans.push_back(tmp);
      --l_index;
      ++r_index;
    }
  }
  while (r_index != r_size) {
    P tmp = r[r_index];
    ++r_index;
    ans.push_back(tmp);
  }
  return ans;
}
vector<P> search(const int& l, const int& r , vector<vector<vector<P>>>& tree) {
  if (tree[l][r].size() != 0) return tree[l][r];
  else return add(search(l, (l+r)/2, tree), search((l+r)/2, r, tree));
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ull n, k;
  cin >> n >> k;

  std::vector<std::vector<vector<P>>> tree(n, std::vector<vector<P>>(n+1, vector<P>()));
  rep(i, n) {
    P tmp;
    cin >> tmp.first;
    tmp.second = 1;
    vector<P> tmp_vec {tmp};
    tree[i][i+1] = tmp_vec;
  }
  rep(i, k) {
    int l, r;
    cin >> l >> r;
    --l;
    tree[l][r] = search(l, r, tree);
    cout << tree[l][r].size() << '\n';
  }
}
