#include <iostream>

double sqrt(double k)
{
  double ans = 0;
  while(ans * ans < k)
  {
    ++ans;
  }
  for(int i = 0;i < 10 ;++i) // i count is similar
  {
    ans = (ans + k/ans)/2.0;
  }
  return ans;
}

int main()
{
  const double quest{[](){double a;std::cin >> a;return a;}()};
  std::cout << sqrt(quest) << '\n';
}
