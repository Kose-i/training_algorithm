#include <iostream>

int main(int argc, char** argv) {
  const unsigned long long N {[](){unsigned long long a;std::cin >> a;return a;}()};
  if (N % 2 != 0) std::cout << "0\n";
  else {
    unsigned long long tmp_prime {N/2};
    unsigned long long five_div_count {};
    unsigned long long five_div {5};
    for (;N>five_div;five_div*=5) {
      five_div_count += tmp_prime / five_div;
    }
    std::cout << five_div_count << '\n';
  }
}
