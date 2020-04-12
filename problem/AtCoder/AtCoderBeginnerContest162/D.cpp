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
bool is_judge(const int& a, const int& b, const int& c) {
  int i = min(a, min(b, c));
  int k = max(a, max(b, c));
  int j = a+b+c - i - k;
  if (j-i==k-j)return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  std::vector<char> S(N);
  rep(i, N) cin >> S[i];
  vector<vector<int>> color_s(3);
  rep(i, N) {
    if (S[i] == 'R') color_s[0].push_back(i+1);
    else if (S[i] == 'G') color_s[1].push_back(i+1);
    else if (S[i] == 'B') color_s[2].push_back(i+1);
  }
  std::sort(color_s.begin(), color_s.end(), [](auto& l , auto& r){return l.size() < r.size();});

  ull answer {};
  for (const auto& e : color_s[0]) {
    for (const auto& f : color_s[1]) {
      for (const auto& g : color_s[2]) {
        if (is_judge(e, f, g) == true) ++answer;
      }
    }
  }
  cout << answer << '\n';
}
