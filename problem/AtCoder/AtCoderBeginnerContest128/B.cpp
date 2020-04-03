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
void mins(T& x, T&& y) {
  x=std::min(x,y);
}

struct P {
  string name;
  int score;
  int num;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<P> X(N);
  rep(i, N) {
    cin >> X[i].name >> X[i].score;
    X[i].num = i+1;
  }
  std::sort(X.begin(), X.end(), [](P& l, P& r){return ((l.name == r.name)?(l.score > r.score):(l.name < r.name));});
  rep(i, N) {
    cout << X[i].num << '\n';
  }
}
