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

ll make_value(const vector<ll>& A, const ll& b, const int& A_size) {
  ll answer {};
  rep(i, A_size) {
    if (A[i] < b+i) {
      answer += (b+i)-A[i];
    } else {
      answer += A[i] - (b+i);
    }
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll min_A{A[0]};
  ll max_A{A[0]};
  rep(i, N) {
    mins(min_A, A[i]);
    maxs(max_A, A[i]);
  }
  ll value {};
  ll left {min_A-N};
  ll left_value {make_value(A, left, N)};
  ll right {max_A+N};
  ll right_value {make_value(A, max_A, N)};
  for(;right-left>1;) {
    ll mid = (left+right)/2;
    if (left_value < right_value) {
      value = make_value(A, mid, N);
      right = mid;
      right_value = value;
      left -= (mid-left)/2;
      left_value = make_value(A, left, N);
    } else {
      value = make_value(A, mid, N);
      left = mid;
      left_value = value;
      right += (right-mid)/2;
      right_value = make_value(A, right, N);
    }
  }
  value = min(left_value, right_value);
  cout << value << '\n';
}
