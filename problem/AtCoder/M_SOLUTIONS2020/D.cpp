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

using P = std::pair<int, int>;
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  std::vector<int> a(n);
  rep(i,n) cin >> a[i];
  P stock_now;
  stock_now.first = 1000; stock_now.second = 0;
  P money_now;
  money_now.first = 1000; money_now.second = 0;
  rep(i, n) {
    P money_next = money_now;
    if (money_next.first < stock_now.first + stock_now.second*a[i]) {
      money_next.first = stock_now.first + stock_now.second*a[i];
      //money_next.second = 0;
    }
    P stock_next = stock_now;
    if (stock_next.second < money_now.first / a[i]) {
      stock_next.second = money_now.first / a[i];
      stock_next.first = money_now.first % a[i];
    } else if (stock_next.second == money_now.first / a[i]) {
      if (stock_next.first < money_now.first % a[i] ) {
        stock_next.first = money_now.first % a[i];
        //stock_next.second = money_now.first / a[i];
      }
    }
    stock_now = stock_next;
    money_now = money_next;
  }
  std::cout << money_now.first << '\n';
}
