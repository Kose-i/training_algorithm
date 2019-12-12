#include <iostream>
#include <vector>

int answer(const int& n, const std::vector<int>& a, const int& k) {
  int left = -1, right = n;
  while (right - left > 1) {
    int mid = (right+left)/2;
    if (a[mid] >= k) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}
int main(int argc, char** argv) {
  const int n {5};
  std::vector<int> a{2, 3, 3, 5, 6};
  int k {3};
  std::cout << answer(n, a, k) << '\n';
}
