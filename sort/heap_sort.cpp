#include <iostream>
#include <vector>

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void max_heap(std::vector<int>& numbers, int root, int bottom) {
  int child = (2 * root) + 1;
  int temp = numbers[root];
  while (child <= bottom) {
    if(child < bottom && numbers[child] < numbers[child + 1]) {
      ++child;
    }
    if(numbers[child] < temp) {
      break;
    } else {
      numbers[(child - 1) / 2] = numbers[child];
      child = (2 * child) + 1;
    }
  }
  numbers[(child - 1) / 2] = temp;
  return;
}
namespace kosei{
  void sort(std::vector<int>& numbers) {
    int array_size = numbers.size();
    for (int i = (array_size - 1) / 2; 0 <= i; --i) {
      max_heap(numbers, i, array_size - 1);
    }
    for(int i = array_size - 1; 0 < i; --i) {
      swap(&numbers[0], &numbers[i]);
      max_heap(numbers, 0 , i - 1);
    }
  }
};

int main(int argc, char** argv) {
  std::vector<int> target{3,2,4,5,3,7,1};
  kosei::sort(target);
  for(const auto& e : target) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}

