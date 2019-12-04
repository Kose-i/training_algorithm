#include <queue>
#include <iostream>

int main(int argc, char** argv) {
  std::priority_queue<int> pque;
  pque.push(3);
  pque.push(5);
  pque.push(1);

  while (!pque.empty()) {
    std::cout << pque.top() << ' ';
    pque.pop();
  }
  std::cout << '\n';
}
