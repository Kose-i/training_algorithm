#include <iostream>
#include <vector>

void sort(std::vector<int>& a)
{
  for(int check = 1;;check = 1){
    for(int i = 0;i < a.size() - 1;++i)
    {
      if(a[i + 1] < a[i])
      {
        int b = a[i + 1];
        a[i + 1] = a[i];
        a[i] = b;
        check = 0;
      }
    }
    if(check)break;
  }
}
int main()
{
  std::vector<int> target{3,2,4,5,3,7,1};
  sort(target);
  for(const int& e : target)
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
  return 0;
}
