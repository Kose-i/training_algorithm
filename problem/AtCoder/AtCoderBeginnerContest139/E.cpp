#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))
using P = std::pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n-1));
  rep(i,n) {
    rep(j,n-1) {
      cin >> a[i][j];
      a[i][j]--;
    }
    std::reverse(a[i].begin(), a[i].end());
  }
  vector<P> q;
  auto check = [&](int i) {
    if (a[i].size() == 0) return;
    int j = a[i].back();
    if (a[j].size() == 0) return;
    if (a[j].back() == i) {
      P p(i,j);
      if (p.second < p.first) swap(p.first, p.second);
      q.push_back(p);
    }
  };
  rep(i,n) {
    check(i);
  }
  int day = 0;
  while (q.size() > 0) {
    day++;
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    vector<P> prevQ;
    swap(prevQ, q);
    for (P p : prevQ) {
      int i = p.first, j = p.second;
      a[i].pop_back();
      a[j].pop_back();
    }
    for (P p : prevQ) {
      int i = p.first, j = p.second;
      check(i);
      check(j);
    }
  }
  rep(i,n) {
    if (a[i].size() != 0) {
      puts("-1");
      return 0;
    }
  }
  cout << day << endl;
  return 0;
}
