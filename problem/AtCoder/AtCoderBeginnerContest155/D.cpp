#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

constexpr ll INF {1000000000000000001};

int main() {
  ll n, k;
  std::cin >> n >> k;
  std::vector<ll> A(n);
  rep(i, n) std::cin >> A[i];
  std::sort(A.begin(), A.end());
  ll left = -INF, right = INF;
  for (ll mid = (left+right)/2;left+1<right;mid = (left+right)/2) {
    bool ok = [&]{
      ll total = 0;
      rep(i, n) {
        if (A[i] < 0) {
          ll l = -1, r = n;
          for (ll c = (l+r)/2;l+1<r;c = (l+r)/2) {
            if (A[c]*A[i] < mid) {
              r = c;
            } else {
              l = c;
            }
          }
          total += n-r;
        } else {
          ll l = -1, r = n;
          for (ll c = (l+r)/2;l+1<r;c = (l+r)/2) {
            if (A[c]*A[i] < mid) {
              l = c;
            } else {
              r = c;
            }
          }
          total += r;
        }
        if (A[i]*A[i] < mid) --total;
      }
      total /= 2;
      return total<k;
    }();
    if (ok) {
      left = mid;
    } else {
      right = mid;
    }
  }
  std::cout << left << '\n';
}
