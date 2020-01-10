#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  unsigned long N;
  unsigned long long M;
  std::cin >> N >> M;
  std::vector<unsigned long long> A(N);

  for (auto& e : A) std::cin >> e;
  std::sort(A.begin(), A.end());

  std::vector<unsigned long> M_candidate;
  for (unsigned long p=0;;++p) {
    unsigned long num = A[N-1]*(p+0.5);
    if (num > M) break;
    M_candidate.push_back(num);
  }
  std::cout << "check\n";
  unsigned long long cnt {};
  for (const auto& num : M_candidate) {
    bool is_check = true;
    for (const auto& e : A) {
      if (num%(e/2) != 0 || num/(e/2)%2==0) {
        is_check = false;
        break;
      }
    }
    if (is_check == false) {
      is_check = true;
    } else {
      ++cnt;
    }
  }
  std::cout << cnt << '\n';
}
