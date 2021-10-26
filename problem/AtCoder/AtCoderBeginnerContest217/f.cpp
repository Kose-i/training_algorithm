#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using Pair = std::pair<int, int>;
using ll = long long;
constexpr ll ll_mod {998244353};

int main() {
    int n, m;
    cin >> n >> m;
    n *= 2;
    vector<vector<ll>> combination(n+1, vector<ll>(n+1, 0)); // TODO
    for (int i=0;i<=n;++i) {
        for (int j=0;j<=n;++j) {
            combination[i][j] = 
        }
    }

    vector<vector<ll>> a(n, vector<ll>(n, 0));
    for (int i=0;i<m;++i) {
        int tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        a[tmp_a-1][tmp_b-1] = 1;
        a[tmp_b-1][tmp_a-1] = 1;
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i=0;i<n-1;++i) dp[i][i+1] = a[i][i+1];
    for (int i=2;i<n;++i) { // pair cnt
        for (int l=0;l+i<n;++l) {
            if (a[l][l+i] == 1) dp[l][l+i] += dp[l+1][l+i-1];
            // hutatuni kugiru
            for (int k=l+1;k<l+i;++k) {
                dp[l][l+i] += dp[l][k]*dp[k+1][l+i] * combination(i, k-l);
                dp[l][l+i] %= ll_mod;
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}
