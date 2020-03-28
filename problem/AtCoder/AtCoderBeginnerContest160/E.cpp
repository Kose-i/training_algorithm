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

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A);
  rep(i, A) cin >> p[i];
  vector<ll> q(B);
  rep(i, B) cin >> q[i];
  vector<ll> r(C);
  rep(i, C) cin >> r[i];

  std::sort(p.rbegin(), p.rend());
  std::sort(q.rbegin(), q.rend());
  std::sort(r.rbegin(), r.rend());

  ++A; ++B; ++C;

  vector<ll> p_sum(A);
  p_sum[0] = 0;
  srep(i, 1, A) {
    p_sum[i] = p_sum[i-1] + p[i-1];
  }
  vector<ll> q_sum(B);
  q_sum[0] = 0;
  srep(i, 1, B) {
    q_sum[i] = q_sum[i-1] + q[i-1];
  }
  vector<ll> r_sum(C);
  r_sum[0] = 0;
  srep(i, 1, C) {
    r_sum[i] = r_sum[i-1] + r[i-1];
  }

  vector<ll> max_pq(C, 0);
  int x_index {X};
  int y_index {Y};
  max_pq[0] = p_sum[X] + q_sum[Y];
  srep(i, 1, C) {
    if (x_index == 0 && y_index == 0) break;
    if (x_index == 0) {
      --y_index;
      max_pq[i] = p_sum[x_index] + q_sum[y_index];
    } else if (y_index == 0) {
      --x_index;
      max_pq[i] = p_sum[x_index] + q_sum[y_index];
    } else if (p[x_index-1] < q[y_index-1]) {
      --x_index;
      max_pq[i] = p_sum[x_index] + q_sum[y_index];
    } else {
      --y_index;
      max_pq[i] = p_sum[x_index] + q_sum[y_index];
    }
  }
  ll max_answer {};
  rep(i, C) {
    if (X+Y < i) break;
    ll tmp = max_pq[i] + r_sum[i];
    maxs(max_answer, tmp);
  }
  cout << max_answer << '\n';
}
