#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::string S;
  std::cin >> S;
  if (N % 2 == 0) {
    int n = N/2;
    std::string s(S.begin(), S.begin() + n);
    std::string S_check = s+s;
    if (S==S_check) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  } else {
    std::cout << "No\n";
  }
}
