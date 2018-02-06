#include <iostream>
#include <vector>

#define M 2 // skip count

typedef struct node *link;
struct node {
  int item;
  link next;
  };
int main(int argc,char* argv[])
{
 std::vector<struct node> target(13);
  target[0].item = 1;
  target[target.size() - 1].item = target.size();
  target[target.size() - 1].next = &target[0];
  for(int i = 0;i < target.size() - 1;++i)
  {
    target[i].item = i + 1;
    target[i].next = &target[i + 1];
  }
 link x = &target[target.size() - 1];
  while(x != x -> next)
  {
    for(int i = 0;i < M;++i)//M
      x = x->next;
    x -> next = (x->next) -> next;
  }
  std::cout << x -> item << '\n';
}
