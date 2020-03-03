#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> t{"Sunny","Cloudy","Rainy"};

int main(int argc, char** argv) {
  std::string S;
  std::cin >> S;
  if (t[0] == S) std::cout << t[1] << '\n';
  else if (t[1] == S) std::cout << t[2] << '\n';
  else if (t[2] == S) std::cout << t[0] << '\n';
}
