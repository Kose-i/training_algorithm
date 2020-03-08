#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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
  string S;
  cin >> S;
  bool is_hitach = true;
  if (S.size()%2 == 1) {
    is_hitach = false;
  } else {
    int c = S.size()/2;
    for (auto i = 0;i < c;++i) {
      if (S[i*2] == 'h' && S[i*2+1] == 'i') {
        continue;
      } else {
        is_hitach = false;
        break;
      }
    }
  }
  if (is_hitach == true) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
