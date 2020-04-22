#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>

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

struct City{
  int idx;
  int year;
  int name_first;
  int name_second;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<City> X(M);
  rep(i, M) {
    X[i].idx = i;
    cin >> X[i].name_first;
    cin >> X[i].year;
  }
  std::sort(X.begin(), X.end(), [](auto& l, auto& r){return ((l.name_first != r.name_first)?(l.name_first<r.name_first):(l.year<r.year));});

  int num {1};
  int tmp_name_first;
  rep(i, M) {
    if (tmp_name_first != X[i].name_first) {
      tmp_name_first = X[i].name_first;
      num = 1;
    }
    X[i].name_second = num;
    ++num;
  }
  std::sort(X.begin(), X.end(), [](auto& l, auto& r){return (l.idx<r.idx);});
  rep(i, M) {
    cout <<std::setfill('0')<<std::setw(6)<< X[i].name_first <<std::setw(6)<< X[i].name_second << '\n';
  }
}
