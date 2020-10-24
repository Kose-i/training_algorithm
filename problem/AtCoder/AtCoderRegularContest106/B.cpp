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

class UnionFind {
  private:
    int node_size;
    std::vector<int> data; // data[0] is not used
  public:
    UnionFind(const int& n=0) : node_size(n+1), data(n+1) {
      for (auto i = 0;i < n+1;++i) {
        data[i] = i;
      }
    }
    int find(const int& x) {
      if (x == data[x]) return x;
      return data[x] = find(data[x]);
    }
    bool unite(int x, int y) {
      x = find(x); y = find(y);
      if (x==y) return false;// is already grooped
      if (data[x] > data[y]) { // swap x<->y
        int tmp = x;
        x = y;
        y = tmp;
      }
      //data[x] += data[y];
      data[y] = x;
      return true;
    }
    bool same(const int& x, const int& y) {
      return (find(x)==find(y));
    }
    int size(const int& x) {
      return -data[find(x)];
    }
};

//int main(int argc, char** argv) {
//  UnionFind uf(5);
//  //group 1 2
//  uf.unite(1, 2);
//  //search 3 4
//  if (uf.same(3,4)) std::cout << "is-group\n";
//  else std::cout << "not-group\n";
//  //group 4 5
//  uf.unite(4,5);
//  //group 3 4
//  uf.unite(3,4);
//  //search 3 5
//  if (uf.same(3,5)) std::cout << "is-group\n";
//  else std::cout << "not-group\n";
//}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<int> c(m);
  vector<int> d(m);
  rep(i, m) cin >> c[i] >> d[i];

  UnionFind uf(n);
  rep(i, m) {
    if (c[i] < d[i]) uf.unite(c[i], d[i]);
    else uf.unite(d[i], c[i]);
  }
  std::map<int, ll> mp;
  rep(i, n) {
    mp[uf.find(i+1)] += a[i] - b[i];
  }
  //for (auto it = mp.begin();it != mp.end();++it) {
  //  cout << it->first << ' ' << it->second << '\n';
  //}
  //return 0;
  bool is_error {false};
  for (auto it = mp.begin();it != mp.end();++it) {
    if (it->second != 0) {
      //cout << it->first << ' ' << it->second << '\n';
      is_error = true;
      break;
    }
  }
  if (is_error == true) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}
