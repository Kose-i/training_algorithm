#include <iostream>
#include <vector>

int main()
{
  unsigned long input{[](){unsigned long a;std::cin >> a;return a;}()};
  std::vector<unsigned long> Fibonacci;
  Fibonacci.push_back(1);
  Fibonacci.push_back(1);
  for(unsigned long i = 2;i < input;++i)
  {
    Fibonacci.push_back(Fibonacci[i - 1] + Fibonacci[i - 2]);
  }
  for(auto& e : Fibonacci)
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
