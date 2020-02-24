#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define rep(i,n) for(int i = 0;i < (n);++i)

ll get_score(const ll& p, const std::vector<ll>& X) {
  ll sum {};
  for (const auto& e : X) {
    sum += (e - p)*(e - p);
  }
  return sum;
}

int main() {
  ll N;
  std::cin >> N;
  std::vector<ll> X(N);
  rep(i,N) std::cin >> X[i];
  std::sort(X.begin(), X.end());
  ll left = 1, right = 100;
  ll left_score = get_score(left, X);
  ll right_score = get_score(right, X);
  for (ll mid = (left+right)/2;left+1<right;mid = (left+right)/2) {
    ll mid_score = get_score(mid, X);
    if (left_score < right_score) {
      right = mid;
      right_score = mid_score;
    } else {
      left = mid;
      left_score = mid_score;
    }
  }
  if (left_score < right_score) std::cout << left_score << '\n';
  else std::cout << right_score << '\n';
}
