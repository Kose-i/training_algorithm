#include <iostream>
#include <vector>

void sort(std::vector<int>& a)
{
  for(int i = 0;i < a.size() - 1;++i)
  {
    if(a[i + 1] < a[i])
    {
      int j;
      for(j = 0;a[j] < a[i + 1];++j){}
      int t = a[i + 1];
      a.erase(a.begin() + i + 1);
      a.insert(a.begin() + j,t);
    }
  }
}
int main()
{
  std::vector<int> target{3,2,4,5,3,7,1};
  sort(target);
  for(int& e : target)
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
