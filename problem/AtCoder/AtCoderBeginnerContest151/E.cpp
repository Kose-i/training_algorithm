#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr long mod_target {1000000007};

long long nCm(int N, int M, vector<vector<long long>>& ncm_memo) {
  if (N==M || M==0) return 1;
  if (ncm_memo[N][M] != 0) return ncm_memo[N][M];
  return ncm_memo[N][M] = nCm(N-1, M-1, ncm_memo) + nCm(N-1, M, ncm_memo);
}

int main(int argc, char** argv) {
  int N, K;
  cin >> N >> K;
  vector<long> A(N);
  for (auto& e : A) cin >> e;
  sort(A.begin(), A.end());
  vector<vector<long long>> ncm_memo(N, vector<long long>(K, 0));

  long long sum_A {};
  for (auto i = 0;i < N;++i) {
    long long min_elem = A[i];
    for (auto j = i+K-1;j < N;++j) {
      long long max_elem = A[j];
      sum_A += (max_elem - min_elem) * nCm(j-i-1, K-2, ncm_memo)%mod_target;
    }
  }
  cout << sum_A % mod_target << '\n';
}
