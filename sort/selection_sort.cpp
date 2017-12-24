#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using Point = std::pair<int,int>;
void swap(int& a, int& b)
{
  int c = a;
  a = b;
  b = c;
}
void sort(std::vector<int>& a)
{
  for(int i = 0;i < a.size();++i)
  {
    Point min;
    min.second = std::numeric_limits<int>::max();
    for(int j = i;j < a.size();++j)
    {
      if(min.second > a[j])
      {
        min.first = j;
        min.second = a[j];
      }
    }
    swap(a[i],a[min.first]);
  }
}
int main()
{
  std::vector<int> target{3,2,4,5,3,7,1};
  sort(target);
  for(auto& e : target)
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
