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

char bit_return(const char& c) {
  if (c == '0') return '1';
  else return '0';
}
vector<char> make_mod(const vector<char>& target) {
  int mod_target {};
  for (const auto& e : target) {
    if (e == '1') ++mod_target;
  }
  vector<char> mod_number(target.size(), '0');
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  map<vector<char>, int> mp;
  vector<char> start(n);
  rep(i, n) cin >> start[i];
  std::reverse(start.begin(), start.end());
  vector<char> empty(n, '0');
  mp[empty] = 0;
  rep(i, n) {
    vector<vector<char>> c_pair;
    vector<char> tmp = start;
    tmp[i] = bit_return(tmp[i]);
    if (mp.find(tmp) != mp.end()) {
      cout << mp[tmp] << '\n';
      continue;
    }
    c_pair.push_back(tmp);
    int size = 1;
    for (;;++size) {
      tmp = make_mod(tmp);
      c_pair.push_back(tmp);
      if (mp.find(c_pair[size]) != mp.end()) break;
    }
    size -= 1;
    for (;size >= 0;--size) {
      mp[c_pair[size]] = mp[c_pair[size+1]] + 1;
    }
    cout << mp[c_pair[0]] << '\n';
  }
}
