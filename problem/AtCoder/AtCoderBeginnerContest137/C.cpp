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

int main() {
  ll N;
  cin >> N;
  vector<std::string> S_box(N);
  rep(i, N) cin >> S_box[i];
  rep(i, N) {
    std::sort(S_box[i].begin(), S_box[i].end());
  }
  std::sort(S_box.begin(), S_box.end());

  ll answer {};
  std::string tmp {};
  bool double_find = false;
  ll cnt {};

  rep(i, N) {
    if (double_find == true && tmp == S_box[i]) {
      ++cnt;
    } else if (double_find == true) {
      tmp = S_box[i];
      answer += cnt*(cnt-1)/2;
      double_find = false;
      cnt = 0;
    } else if (tmp == S_box[i]) {
      cnt = 2;
      double_find = true;
    } else {
      tmp = S_box[i];
    }
  }
  answer += cnt*(cnt-1)/2;
  cout << answer << '\n';
}
