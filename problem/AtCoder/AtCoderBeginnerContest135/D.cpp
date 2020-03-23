#include <algorithm>
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

template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

vector<ull> move_bits(const vector<ull>& t, const int& c) {
  vector<ull> ans = t;
  for (int i = 0;i < 13;++i) {
    int j = (i + c)%13;
    ans[j] = t[i];
  }
  return ans;
}

void set_bits(vector<ull>& t) {
  vector<vector<ull>> vec(10, vector<ull>(13));
  for (int i = 1;i < 10;++i) {
    vec[i] = move_bits(t, i);
  }
  for (int i = 0;i < 13;++i) {
    for (int j = 0;j < 10;++j) {
      t[i] += vec[j][i];
    }
  }
}
int main() {
  string S;
  cin >> S;
  vector<ull> A(13, 0);
  for (int i = S.size()-1; i >= 0;--i) {
    if (S[i] == '?') {
      set_bits(A);
    } else {
      int c = S[i] - '0';
      A = move_bits(A, c);
    }
    for (const auto& e : A) {
      cout << e << ' ';
    }
    cout << '\n';
  }
  cout << A[5] << '\n';
}
