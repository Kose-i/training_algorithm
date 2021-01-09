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

void print_vec(const std::vector<int>& num) {
  bool no_first {false};
  for (const auto& e : num) {
    if (no_first) cout << ',';
    cout << e;
    no_first = true;
  }
  cout << '\n';
}

std::vector<int> multiple(const std::vector<int>& num1, const std::vector<int>& num2, const ll& m) {

  std::vector<int> ans(2);
  ans[0]  = num1[0] * num2[0];
  ans[1]  = num1[1] * num2[0];
  ans[1] += num1[0] * num2[1];
  ans[1] += ans[0] / m;

  ans[0] %= m;
  ans[1] %= m;
  return ans;
}
std::vector<int> make_number(const ll& n, const ll& m) {
  std::vector<int> num {1, 0};
  if (n < 1) {
    return num;
  }

  std::vector<int> upper_num(2);
  upper_num[0] = 10 % m;
  upper_num[1] = 10 / m;

  for (ll i = n;0 < i; i>>=1) {
    if (i&1) {
      num = multiple(num, upper_num, m);
    }
    upper_num = multiple(upper_num, upper_num, m);
  }
  return num;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  std::vector<int> number = make_number(n, m);

  cout << number[1] << '\n';
}
