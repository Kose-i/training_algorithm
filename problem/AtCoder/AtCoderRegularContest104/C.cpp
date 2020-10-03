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

struct Elevator {
  int start_step, end_step;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Elevator> person(n);
  rep(i, n) {
    cin >> person.start_step >> person.end_step;
  }

  int now_pos {1};
  bool is_ok {true};
  rep(i, n) {
    if (person[i].start_step != -1 && person[i].end_step != -1) {
      int need_person = person[i].end_step - person[i].start_step - 1;
      if (need_person == 0 && (person[i].start_step-now_pos)%2== 0) {
        is_ok = false;
      }
      int used_before = (person[i].start_step - now_pos)/2 * 2;
      now_pos = need_person - used_before + person[i].end_step;
      if (person[i].start_step - now_pos)
    }
  }

}
