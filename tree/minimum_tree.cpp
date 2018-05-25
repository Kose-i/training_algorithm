#include <iostream>
#include <vector>

typedef struct tree* link;
struct tree
{
  int item;
  link right_link;
  link left_link;
};
void add_tree(std::vector<struct tree>& node, const int new_item)
{
  if(node.size() == 0)
  {
    struct tree prime;
    prime.item = new_item;
    prime.right_link = nullptr;
    prime.left_link = nullptr;
    node.push_back(prime);
  }
  else{
    link pos = &node[0];
    while(true)
    {
      if((*pos).item < new_item)
      {
        if((*pos).right_link != nullptr){pos = (*pos).right_link;}
        else{
          struct tree prime;
          prime.item = new_item;
          prime.right_link = nullptr;
          prime.left_link = nullptr;
          node.push_back(prime);
          (*pos).right_link = (&(node[node.size() - 1]));
          break;
        }
      }
      else {
        if((*pos).left_link != nullptr){pos = (*pos).left_link;}
        else{
          struct tree prime;
          prime.item = new_item;
          prime.right_link = nullptr;
          prime.left_link = nullptr;
          node.push_back(prime);
          (*pos).left_link = (&(node[node.size() - 1]));
          break;
        }
      }
    }
  }
}
void print_sort_data(link pos)
{
  if(pos == nullptr)return;
  //left
  print_sort_data((*pos).left_link);
  std::cout << "left checked\n";
  //self
  std::cout << (*pos).item << ' ';
  //right
  print_sort_data((*pos).right_link);
  std::cout << "right checked\n";
}
int main()
{  
  std::vector<int> target{3,2,4,5,3,7,1};
  std::vector<struct tree> node;
  for(const int& e : target)
  {
    std::cout << e << ' ';
    add_tree(node,e);
  }
  std::cout << '\n';
  print_sort_data(&node[0]);
}
