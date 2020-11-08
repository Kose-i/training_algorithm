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

struct Point {
  int x, y;
};
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w, n, m;
  cin >> h >> w >> n >> m;

  vector<int> a(n); 
  vector<int> b(n); 
  vector<int> c(m); 
  vector<int> d(m); 
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, m) cin >> c[i] >> d[i];

  std::vector<Point> power;
  rep(i, n) {
    Point p; p.y = a[i]; p.x = b[i];
    power.push_back(p);
  }

  std::vector<Point> rock;
  rep(i, n) {
    Point p; p.y = a[i]; p.x = b[i];
    rock.push_back(p);
  }
  rep(i,m) {
    Point p; p.y = c[i]; p.x = d[i];
    rock.push_back(p);
  }

  int ans {h*w};
  
  std::sort(power.begin(), power.end(), [](auto l, auto r){return (l.x==r.x)?(l.x<r.x):(l.y<r.y);});
  std::sort(rock.begin(), rock.end(), [](auto l, auto r){return (l.x==r.x)?(l.x<r.x):(l.y<r.y);});

  rep(i, n) {
    Point lx; lx.x = power[i].x-1; lx.y = power[i].y;
    int lb = std::lower_bound(rock.begin(), rock.end(), lx);
    Point rx; rx.x = power[i].x+1; rx.y = power[i].y;
    int ub = std::upper_bound(rock.begin(), rock.end(), rx);
    cout << lb << ' ' << ub << '\n';
  }
}
