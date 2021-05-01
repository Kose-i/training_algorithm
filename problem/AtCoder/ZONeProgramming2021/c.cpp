#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <functional>

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
struct DataType {
  int a, b, c, d, e;
};

bool op1(DataType& l, DataType& r) {
  return l.a < r.a;
}
bool op2(DataType& l, DataType& r) {
  return l.b < r.b;
}
bool op3(DataType& l, DataType& r) {
  return l.c < r.c;
}
bool op4(DataType& l, DataType& r) {
  return l.d < r.d;
}
bool op5(DataType& l, DataType& r) {
  return l.e < r.e;
}
int make_data(const DataType& d1, const DataType& d2, const DataType& d3, DataType& p) {
  p.a = std::max(d1.a, std::max(d2.a, d3.a));
  p.b = std::max(d1.b, std::max(d2.b, d3.b));
  p.c = std::max(d1.c, std::max(d2.c, d3.c));
  p.d = std::max(d1.d, std::max(d2.d, d3.d));
  p.e = std::max(d1.e, std::max(d2.e, d3.e));
  int min_val = std::min(p.a, std::min(p.b, std::min(p.c, std::min(p.d, p.e))));
  if (min_val == p.a) return 1;
  if (min_val == p.b) return 2;
  if (min_val == p.c) return 3;
  if (min_val == p.d) return 4;
  return 5;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;
  vector<DataType> data(n);
  rep(i, n) cin >> data[i].a >> data[i].b >> data[i].c >> data[i].d >> data[i].e;

  DataType now_max {};
  int weak_point = make_data(data[0], data[1], data[2], now_max);
  const vector<std::function<bool(const DataType&, const DataType&)>> op {op1, op2, op3, op4, op5};
  std::sort(data.begin(), data.end(), op[weak_point]);
}