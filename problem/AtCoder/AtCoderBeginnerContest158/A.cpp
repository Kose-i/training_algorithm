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

  bool is_no = false;
  rep(i,2) {
    if (S[i]!=S[2]) is_no = true;
  }
  if (is_no == true) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

}
