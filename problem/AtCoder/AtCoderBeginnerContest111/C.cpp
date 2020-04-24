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

  int N;
  cin >> N;
  vector<int> v(N);
  rep(i, N) cin >> v[i];

  vector<int> a(N/2);
  vector<int> b(N/2);
  rep(i, N) {
    if (i%2==0) a[i/2] = v[i];
    else b[i/2] = v[i];
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  P max_a, double_max_a;
  int max_cnt {0};
  int max_tmp_num {a[0]};
  rep(i, N/2) {
    if (a[i] == max_tmp_num) {
      ++max_cnt;
    } else {
      if (max_a.second < max_cnt) {
        double_max_a = max_a;
        max_a.first  = max_tmp_num;
        max_a.second = max_cnt;
      } else if (double_max_a.second < max_cnt) {
        double_max_a.first  = max_tmp_num;
        double_max_a.second = max_cnt;
      }
      max_tmp_num = a[i];
      max_cnt = 1;
    }
  }
  if (max_a.second < max_cnt) {
    double_max_a = max_a;
    max_a.first  = max_tmp_num;
    max_a.second = max_cnt;
  } else if (double_max_a.second < max_cnt) {
    double_max_a.first  = max_tmp_num;
    double_max_a.second = max_cnt;
  }
  P max_b, double_max_b;
  max_cnt = 0;
  max_tmp_num = b[0];
  rep(i, N/2) {
    if (b[i] == max_tmp_num) {
      ++max_cnt;
    } else {
      if (max_b.second < max_cnt) {
        double_max_b = max_b;
        max_b.first  = max_tmp_num;
        max_b.second = max_cnt;
      } else if (double_max_b.second < max_cnt) {
        double_max_b.first  = max_tmp_num;
        double_max_b.second = max_cnt;
      }
      max_tmp_num = b[i];
      max_cnt = 1;
    }
  }
  if (max_b.second < max_cnt) {
    double_max_b = max_b;
    max_b.first  = max_tmp_num;
    max_b.second = max_cnt;
  } else if (double_max_b.second < max_cnt) {
    double_max_b.first  = max_tmp_num;
    double_max_b.second = max_cnt;
  }

  //cout << max_a.second << ' ' << max_a.first << '\n';
  //cout << max_b.second << ' ' << max_b.first << '\n';

  int answer {};
  if (max_a.first == max_b.first) {
    answer = N - max_a.second - double_max_b.second;
    min(answer, N - double_max_a.second - max_b.second);
  } else {
    answer = N - max_a.second - max_b.second;
  }
  cout << answer << '\n';
}
