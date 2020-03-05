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
  ll N;
  std::cin >> N;
  vector<vector<int>> A(N, vector<int>(N-1));
  rep(i,N) rep(j,N-1) cin >> A[i][j];
  ll day {};
  bool is_ok = true;
  for (day = 0;;++day) {
    vector<int> vec(N, -1);
    rep(i,N) {
      rep(j,N-1) {
        if (A[i][j] != -1) {
          vec[i] = A[i][j];
          break;
        }
      }
    }
    //vec
    bool is_check = false;
    vector<int> update_num;
    rep(i,N) {
      if (vec[i] == -1) {
        continue;
      } else if (i+1 == vec[vec[i] - 1]) {
        update_num.push_back(i);
      } else {
        is_check = true;
      }
    }
    if (is_check == false && update_num.size() == 0) break; // finish
    //update
    if (update_num.size() == 0) {
      is_ok = false;
      break;
    } else {
      for (const auto& i : update_num) {
        rep(j,N-1) {
          if (A[i][j] != -1) {
            A[i][j] = -1;
            break;
          }
        }
      }
    }
  }
  if (is_ok == true) {
    std::cout << day << '\n';
  } else {
    std::cout << "-1\n";
  }
}
