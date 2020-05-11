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

vector<int> make_char_cnt(const vector<char>& S, const int& index) {
  vector<int> answer(26, 0);
  rep(i, index) {
    ++answer[S[i]-'a'];
  }
  return answer;
}
int get_same(const vector<int>& X, const vector<int>& S) {
  int answer {};
  rep(i, 26) {
    if (X[i]>0 && (S[i]-X[i])>0) {
      ++answer;
    }
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<char> S(N);
  rep(i, N) cin >> S[i];

  vector<int> char_cnt(26, 0);
  rep(i, N) {
    ++char_cnt[S[i]-'a'];
  }
  int answer {};
  rep(i,N) {
    vector<int> X = make_char_cnt(S, i);
    maxs(answer, get_same(X, char_cnt));
  }
  cout << answer << '\n';
}
