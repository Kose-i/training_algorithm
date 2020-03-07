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

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))

vector<ll> transform_vec(10000, 0);
void init_transform_mod_vec(const ll& P) {
  for (auto i = 0;i < P;++i) {
    transform_vec[i] = i*10 % P;
  }
}
void shift_vec(vector<ll>& p, ll c, const ll& P) {
  vector<ll> tmp = p;
  for (auto i = 0;i < P;++i) {
    p[i] = 0;
  }
  for (auto i = 0;i < P;++i) {
    p[transform_vec[i]] += tmp[i];
    if (i+c >= P) {
      p[i+c-P] += tmp[i];
    } else {
      p[i+c] += tmp[i];
    }
  }
}

void print_vec(const vector<ll>& t) {
  for (const auto& e : t) {
    cout << e << ' ';
  }
  cout << '\n';
}

int main() {
  ll N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  vector<ll> mod_vec(P, 0);
  ull answer {};
  init_transform_mod_vec(P);
  rep(i, N) {
    ll c = (S[i]-'0')%P;
    shift_vec(mod_vec, c, P);

    ++mod_vec[c];
    answer += mod_vec[0];
  }
  cout << answer << '\n';
}
