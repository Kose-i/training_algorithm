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

struct P {
  char flag;
  char Start_or_End; // Start is 1
  char character;
};

int main() {
  string S;
  cin >> S;
  ll Q;
  cin >> Q;
  vector<P> query(Q);
  rep(i,Q) {
    cin >> query[i].flag;
    if (query[i].flag == '1') {
      continue;
    } else {
      cin >> query[i].Start_or_End >> query[i].character;
    }
  }

  bool is_back = false;
  string Top;
  string Tail;
  rep(i,Q) {
    if (query[i].flag == '1') {
      is_back = !is_back;
    } else {
      if (query[i].Start_or_End == '1') {
        if (is_back == false) {
          Top += query[i].character;
        } else {
          Tail += query[i].character;
        }
      } else { // '2'
        if (is_back == false) {
          Tail += query[i].character;
        } else {
          Top += query[i].character;
        }
      }
    }
  }
  if (is_back == true) {
    for (auto it = Tail.rbegin(); it != Tail.rend(); ++it) {
      cout << *it;
    }
    for (auto it = S.rbegin(); it != S.rend(); ++it) {
      cout << *it;
    }
    cout << Top << '\n';
  } else {
    for (auto it = Top.rbegin(); it != Top.rend(); ++it) {
      cout << *it;
    }
    cout << S << Tail << '\n';
  }
}
