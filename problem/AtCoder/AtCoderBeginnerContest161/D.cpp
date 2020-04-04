#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int K;
  cin >> K;

  std::queue<ll> p;
  ll answer {};
  srep(i,1,10) {
    answer = i;
    p.push(answer);
    --K;
    if (K==0) break;
  }
  if (K==0) {
    cout << answer << '\n';
    return 0;
  }
  for (;true;) {
    answer = p.front(); p.pop();
    if (answer % 10 != 0) {
      p.push(answer*10+((answer%10)-1));
      --K;
      if (K == 0) {
        answer = answer*10 +(answer%10)- 1;
        break;
      }
    }
    p.push(answer*10+(answer%10));
    --K;
    if (K==0) {
      answer = answer*10+(answer%10);
      break;
    }
    if (answer % 10 != 9) {
      p.push(answer*10+(answer%10)+1);
      --K;
      if (K == 0) {
        answer = answer*10+(answer%10)+1;
        break;
      }
    }
  }
  //for (;!p.empty();p.pop()) {
  //  cout << p.front() << ' ';
  //}
  cout << answer << '\n';
}
