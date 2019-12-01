#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::vector<int> money_chips {100, 101, 102, 103, 104, 105};
  int input_money {};
  std::cin >> input_money;
  int count = input_money / 100;
  int mod = input_money % 100;
  int top = 5*count;
  if (mod <= top) {
    std::cout << "1\n";
  } else {
    std::cout << "0\n";
  }
}
