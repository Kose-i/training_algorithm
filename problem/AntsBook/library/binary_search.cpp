#include <iostream>
#include <vector>

template<typename T>
int binary_search(const std::vector<T>& vector_, const T& key) {
  int left = 0, right = vector_.size();
  while (right - left >= 1) {
    int mid = (left + right)/2;
    if (vector_[mid] == key) return mid;
    else if (vector_[mid] > key) left = mid + 1;
    else right = mid;
  }
  return -1;
}
