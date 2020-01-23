#include <iostream>
#include <vector>

int d(unsigned long long N) {
  int sum_keta {1};
  while (N / 10) {
    N/= 10;
    ++sum_keta;
  }
  return sum_keta;
}

bool is_ok(const unsigned long long& A, const unsigned long long& N, const unsigned long long& B, const unsigned long long& x) {
  return (A*N+B*d(N)<=x);
}

int main(int argc, char** argv) {
  unsigned long A, B;
  unsigned long long X;
  std::cin >> A >> B >> X;
  unsigned long long left =0;
  unsigned long long right = 1000000000;
  for (;right - left > 1;) {
    unsigned long long mid = (left + right)/2;
    if(is_ok(A, mid, B, X)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  if (is_ok(A, right, B, X)) {
    std::cout << right << '\n';
  } else {
    std::cout << left  << '\n';
  }
}
