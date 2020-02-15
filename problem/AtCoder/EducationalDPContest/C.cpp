#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<long long> a(N);
  std::vector<long long> b(N);
  std::vector<long long> c(N);
  for (auto i = 0;i < N;++i) std::cin >> a[i] >> b[i] >> c[i];
  std::vector<std::vector<long long>> max_happines(N, std::vector<long long>(3, 0));
  max_happines[0][0] = a[0];
  max_happines[0][1] = b[0];
  max_happines[0][2] = c[0];
  for (auto i = 1;i < N;++i) {
    max_happines[i][0] = std::max(max_happines[i-1][1], max_happines[i-1][2])+a[i];
    max_happines[i][1] = std::max(max_happines[i-1][0], max_happines[i-1][2])+b[i];
    max_happines[i][2] = std::max(max_happines[i-1][0], max_happines[i-1][1])+c[i];
  }

  long long max_happy = std::max(max_happines[N-1][0], max_happines[N-1][1]);
  max_happy = std::max(max_happy, max_happines[N-1][2]);
  std::cout << max_happy << '\n';
}
