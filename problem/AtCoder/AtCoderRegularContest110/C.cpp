#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stack>

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

struct Path {
  int up_num;
  int down_num;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; cin >> n;

  std::vector<int> perm(n);
  rep(i, n) {
    cin >> perm[i];
    --perm[i];
  }
  //std::vector<int> perm_idx(n);
  //rep(i, n) {
  //  perm_idx[perm[i]] = i;
  //}

  bool is_error {false};
  //std::vector<int> ans_idx;

  int sort_idx {};

  std::vector<int> ans;
  std::stack<int> ans_tmp;

  rep(i, n) {
    if (perm[sort_idx] < i) {
      //sort_idx = i;
      for (;ans_tmp.size() != 0;) {
        ans.push_back(ans_tmp.top());
        ans_tmp.pop();
      }
      ans_tmp.push(i+1);
    } else if (perm[i] > i) {
      if (perm[sort_idx] <= perm[i]) {
        sort_idx = i;
        ans_tmp.push(i+1);
      } else {
        is_error = true;
        break;
      }
    } else {
      is_error = true;
      break;
    }
  }

  if (is_error || (ans.size() != n-1)) {
    cout << "-1\n";
  } else {
    for (const auto& e : ans) {
      cout << e << '\n';
    }
  }
}
