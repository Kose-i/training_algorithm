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
struct Name {
    std::string s;
};

map<char, int> mp;

bool operator<(Name& l, Name& r) {
    for (auto i = 0; i < l.s.size() && i < r.s.size();++i) {
        if (mp[l.s[i]] > mp[r.s[i]]) return false;
        if (mp[l.s[i]] < mp[r.s[i]]) return true;
    }
    return l.s.size() > r.s.size();
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s;
  int n;
  cin >> s >> n;
  for (int i = 0;i < s.size();++i) {
    mp[s[i]] = s.size()-i;
//    cout << "mp[" << s[i] << "]=" << s.size() - i << ',';
  }
  vector<Name> s_box(n);
  for (int i=0;i<n;++i) cin>>s_box[i].s;

  std::sort(s_box.rbegin(), s_box.rend());
  for (auto i = 0;i < n;++i) cout << s_box[i].s << '\n';
}
