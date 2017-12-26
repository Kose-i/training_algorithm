#include <iostream>
#include <vector>

int povita(std::vector<int>& a,int first,int last)
{
  int check = first + 1;
  while(check <= last && a[first] == a[check])check++;
  if(check >= last)return -1;
  return check;
}
void swap(int* a,int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(std::vector<int>& a,int first,int last)
{
  int k = first;
  int m = last;
  int p = povita(a,first,last);
  if(p == -1)return -1;
  while(k < m){
    while(k <= last && a[k] < a[p])++k;//a[k] | p <=  a[k]
    while(first <= m && a[p] <= a[m])--m;//a[m] | a[m] < p
    if(k < m)
    {
      swap(&a[k],&a[m]);
    }
  }
  return k - 1;
}
void quick_sort(std::vector<int>& a,int first,int last)
{
  int cong = partition(a,first,last);
  if(cong != -1)
  {
    quick_sort(a,first,cong);
    quick_sort(a,cong + 1,last);
  }
  return;
}
void sort(std::vector<int>& a)
{
  quick_sort(a,0,a.size() - 1);
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
