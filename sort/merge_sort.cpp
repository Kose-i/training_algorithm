#include <iostream>
#include <vector>

void merge(std::vector<int> split1,std::vector<int> split2, std::vector<int>& answer)
{
  int i = 0,j = 0;
  while(i < split1.size() || j < split2.size())
  {
    if(split2.size() <= j || i < split1.size() && split1[i] < split2[j])
    {
      answer[i + j] = split1[i];
      ++i;
    }
    else{
      answer[i + j] = split2[j];
      ++j;
    }
  }
}
void merge_sort(std::vector<int>& a)
{
  if(a.size() > 1)
  {
    std::vector<int> b(a.begin(),a.begin() + a.size()/2 );
    std::vector<int> c(a.begin() + a.size()/2 ,a.end());
    merge_sort(b);
    merge_sort(c);
    merge(b,c,a);
  }
}
void sort(std::vector<int>& a)
{
  merge_sort(a);
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
