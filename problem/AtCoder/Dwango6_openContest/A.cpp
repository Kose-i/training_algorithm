#include <iostream>

int main(int argc, char** argv) {
  int H, W;
  std::cin >> H >> W;
  if (H*W <= 1) {
    std::cout << "No\n";
    return 0;
  } else if (H*W == 2) {
    for (auto i = 0;i < H;++i) {
      for (auto j = 0;j < W;++j) {
        std::cout << '2';
      }
      std::cout << '\n';
    }
  } else if (H*W == 5) {
    for (auto i = 0;i < H;++i) {
      for (auto j = 0;j < W;++j) {
        std::cout << '5';
      }
      std::cout << '\n';
    }
  } else if (H==1 && W%7==0) {
    int k = 0;
    int num = 2;
    for (auto i = 1;i <= W;++i) {
      if (num == 2 && k == 2) {
        num = 5;
        k = 0;
      } else if (num == 5 && k == 5) {
        num = 2;
        k = 0;
      }
      std::cout << num;
      ++k;
    }
    std::cout << '\n';
  } else if (W==1 && H%7==0) {
    int k = 0;
    int num = 2;
    for (auto i = 1;i <= H;++i) {
      if (num == 2 && k == 2) {
        num = 5;
        k = 0;
      } else if (num == 5 && k == 5) {
        num = 2;
        k = 0;
      }
      std::cout << num;
      ++k;
      std::cout << '\n';
    }
  } else {
    std::cout << "No\n";
  }
}
