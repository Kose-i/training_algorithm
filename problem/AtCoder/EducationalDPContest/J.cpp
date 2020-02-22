#include <iostream>
#include <vector>
#include <stdio.h>

#include <iomanip>

#define rep(i, n) for(int i = 0;i < (n);++i)

using ll = long long;
using namespace std;

double rec(int a, int b, int c, const int& N, std::vector<std::vector<std::vector<double>>>& dp) {
 
	if (dp[a][b][c] != 0) return dp[a][b][c];
	if (a == 0 && b == 0 && c == 0) return 0;
	double su = a + b + c; // 残りの枚数
	double res = 1.0 * (double)N / su;
	if (a > 0) res += rec(a - 1, b + 1, c, N, dp) * (a / su);
	if (b > 0) res += rec(a, b - 1, c + 1, N, dp) * (b / su);
	if (c > 0) res += rec(a, b, c - 1, N, dp) *(c / su);
	return dp[a][b][c] = res;
}
void solve() {
  int N;
	cin >> N;
  std::vector<std::vector<std::vector<double>>> dp(305, std::vector<std::vector<double>>(305, std::vector<double>(305, 0)));
  std::vector<int> a(3, 0);
	for (size_t i = 0; i < N; i++)
	{
		int b;
		cin >> b;
		if (b == 0) continue;
		a[3 - b]++;
	}
	cout << fixed << setprecision(10) << rec(a[0], a[1], a[2], N, dp) << endl;
}
int main() {
  solve();
}
