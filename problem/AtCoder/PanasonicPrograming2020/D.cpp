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

vector<std::string> make_char(const int& N) {
  if (N==1) {
    vector<std::string> tmp{"a"};
    return tmp;
  } else if (N==2) {
    vector<std::string> tmp{"aa", "ab"};
    return tmp;
  } else {
    vector<std::string> tmp(N);
    vector<std::string> ans = make_char(N-1);
    rep(i, N-1) {
      tmp[i] = ans[i] + ((char)('a'+i));
    }
    tmp[N-1] = ans[0] + "b";
    std::sort(tmp.begin(), tmp.end());
    return tmp;
  }
}

int main() {
  int N;
  cin >> N;
  vector<string> answer = make_char(N);
  rep(i, N) {
    cout << answer[i] << '\n';
  }
  return 0;
}
