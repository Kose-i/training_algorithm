#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <deque>

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

struct DataType {
  char t; bool front;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  cin >> s;

  bool is_front {false};
  int n {};
  std::vector<DataType> data;
  for (const auto& e : s) {
    if (e == 'R') is_front = !is_front;
    else {
      DataType tmp; tmp.front = is_front;
      tmp.t = e;
      data.push_back(tmp);
      ++n;
    }
  }
  std::vector<char> ans(n);
  int front_idx {};
  int end_idx {n-1};
  for (int i = n-1;0 <= i;--i) {
    if (data[i].front == true) ans[front_idx++] = data[i].t;
    else ans[end_idx--] = data[i].t;
  }
  if (is_front) {
    std::reverse(ans.begin(), ans.end());
  }

  std::deque<int> deq;
  for (int i = 0;i < n;++i) {
    if (deq.size() == 0) deq.push_front(i);
    else if (ans[deq.front()] == ans[i]) deq.pop_front();
    else deq.push_front(i);
  }
  //print
  for (;deq.size() != 0;) {
    cout << ans[deq.back()];
    deq.pop_back();
  }
  cout << '\n';
}
