#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

struct Party{
  int number;
  ull A;
};

using P=std::pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<Party> Member(N);
  rep(i, N) {
    Member[i].number = i+1;
    cin >> Member[i].A;
  }

  vector<P> X(N);
  rep(i, N) {
    X[i].first  = Member[i].number + Member[i].A;
    X[i].second = Member[i].number - Member[i].A;
  }

  std::unordered_map<int, int> mp;
  ull ans {};
  rep(i, N) {
    ans += mp[X[i].second];
    ++mp[X[i].first];
  }

  cout << ans << '\n';
}
