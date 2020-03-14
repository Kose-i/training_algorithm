#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF
constexpr int INT_INF {1000000000};

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))

bool is_match(const string& l, const string& r, const int p) {
  int l_size = l.size();
  int r_size = r.size();
  for (auto i = p, j = 0;i < l_size && j < r_size;++i, ++j) {
    if (l[i] == r[j]) continue;
    else if ((l[i] == '?') || (r[j] == '?')) continue;
    else return false;
  }
  return true;
}
string make_match(const string& l, const string& r, const int p) {
  string S;
  int l_size = l.size();
  int r_size = r.size();
  int l_pos = 0, r_pos = 0;
  for (l_pos = 0;l_pos < p;++l_pos) {
    S += l[l_pos];
  }
  for (;l_pos < l_size;++l_pos, ++r_pos) {
    if (l[l_pos] != '?') S+=l[l_pos];
    else S += r[r_pos];
  }
  for (;r_pos < r_size;++r_pos) {
    S += r[r_pos];
  }
  return S;
}

int make_answer(const string& l1, const string& l2, const string& l3) {
  int l1_size = l1.size();
  string S;
  for (auto i = 0;i < l1_size;++i) {
    if (is_match(l1, l2, i)) {
      S = make_match(l1, l2, i);
      break;
    }
  }
  int S_size = S.size();
  if (S_size == 0) {
    S = l1 + l2;
  }

  string S2;
  for (auto i = 0;i < S_size;++i) {
    if (is_match(S, l3, i)) {
      S2 = make_match(S, l3, i);
      break;
    }
  }
  if (S2.size() == 0) {
    S2 = S + l3;
  }
  return S2.size();

}

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  int ans = make_answer(a, b, c);
  mins(ans, make_answer(b, a, c));
  mins(ans, make_answer(b, c, a));
  mins(ans, make_answer(c, b, a));
  mins(ans, make_answer(a, c, b));
  mins(ans, make_answer(c, a, b));
  cout << ans << '\n';
}
