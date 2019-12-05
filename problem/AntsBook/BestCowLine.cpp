#include <iostream>

std::string search(const std::string& S, const int& left, const int& right) {
  if (left == right) {
    std::string char_point {"a"};
    char_point[0] = S[left];
    return char_point;
  }
  std::string ans_sub {""};
  if (S[left] < S[right]) {
    return S[left] + search(S, left+1, right);
  } else if (S[left] > S[right]) {
    return S[right] + search(S, left, right-1);
  } else {
    bool is_left = false;
    for (auto i = 0; left + i <= right; ++i) {
      if (S[left + i] < S[right - i]) {
        is_left = true;
        break;
      } else if (S[left + i] > S[right - i]) {
        is_left = false;
        break;
      }
    }
    if (is_left == true) return S[left] + search(S, left+1, right);
    else return S[right] + search(S, left, right-1);
  }
}
std::string answer(const std::string& S) {
  int S_size = S.size();
  return search(S, 0, S_size-1);
}

int main(int argc, char** argv) {
  std::string S;
  std::cin >> S;
  std::cout << answer(S) << '\n';
}
