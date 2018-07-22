#include <iostream>
#include <vector>

#define M 5 // skip count

typedef struct node *link;
struct node {
  int item;
  link next;
};

int main(int argc,char** argv) {
  unsigned block_size {};
  std::cout << "input size :";
  std::cin >> block_size;
  std::vector<struct node> target(block_size);
  std::cin >> target[0].item;
  target[target.size() - 1].item = target.size();
  target[target.size() - 1].next = &target[0];
  for(int i {};i < target.size() - 1;++i) {
    std::cin >> target[i].item;
    target[i].next = &target[i + 1];
  }
 link x = &target[target.size() - 1];
  while(x != x -> next) {
    for(int i = 0;i < M;++i)//M
      x = x->next;
    x -> next = (x->next) -> next;
  }
  std::cout << x -> item << '\n';
}
