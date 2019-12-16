#include <iostream>
#include <vector>
#include <cmath>

constexpr int ST_SIZE = (1<<15) -1;
constexpr int MAX_N = 10000;
constexpr int MAX_C = 10000;

std::vector<double> vx(ST_SIZE), vy(ST_SIZE), ang(ST_SIZE);

std::vector<double> prv(MAX_N);

void init(int k, int l, int r, const std::vector<int>& L) {
  ang[k] = vx[k] = 0.0;

  if (r - l == 1) {
    vy[k] = L[l];
  } else {
    int chl = k*2+1, chr = k*2+2;
    init(chl, l, (l+r)/2, L);
    init(chr, (l+r)/2, r, L);
    vy[k] = vy[chl] + vy[chr];
  }
}

void change(int s, double a, int v, int l, int r) {
  if (s <= l) return;
  if (s < r) {
    int chl = v*2+1, chr = v*2+2;
    int m = (l+r)/2;
    change(s, a, chl, l, m);
    change(s, a, chr, m, r);
    if (s <= m) ang[v] += a;

    double s = std::sin(ang[v]), c = std::cos(ang[v]);
    vx[v] = vx[chl] + (c*vx[chr] - s*vy[chr]);
    vy[v] = vy[chl] + (s*vx[chr] + c*vy[chr]);
  }
}
void answer(const int N, const int C, const std::vector<int> L, const std::vector<int> S, const std::vector<int> A) {
  init(0, 0, N, L);
  for (auto i = 0;i < 2*N;++i) std::cout << vy[i] << ' ';
  std::cout << '\n';

  for (auto i = 1;i < N;++i) prv[i] = M_PI;

  for (int i = 0;i < C;++i) {
    int s = S[i];
    double a = A[i] / 360.0 * 2 * M_PI;

    change(s, a - prv[s], 0, 0, N);
    prv[s] = a;
    std::cout << vx[0] << ' ' << vy[0] << '\n';
  }
}
int main(int argc, char** argv) {
  const int N {3};
  const int C {2};
  const std::vector<int> L {5, 5, 5};
  const std::vector<int> S {1, 2};
  const std::vector<int> A {270, 90};
  answer(N, C, L, S, A);
}
