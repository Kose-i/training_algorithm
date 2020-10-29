#include <iostream>

bool is_check(const int num) {
  int check = num*3 + 1;
  while (check != 1) {
    check = ((check%2==0)?check/2:(check*3+1));
    if (check == num) return true;
  }
  return false;
}

int main(int argc, char** argv) {
  int cnt {};
  for (int number = 2;number <= 10000;number += 2) {
    if (is_check(number)) {
      ++cnt;
    }
  }
  std::cout << cnt << '\n';
}
