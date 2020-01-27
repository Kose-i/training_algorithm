#include <iostream>
#include <vector>

struct Num {
  public:
    Num(int c) : num(c), den(1){}
    Num op(const Num& l, const Num& r, char)
    int to_int() {
      if (num%den != 0) return -1;
      return num/den;
    }
  private:
    int den, num;
};

int eval(const int& i, const char& c1, const char& c2, const char& c3) {
  if (c1=='~' && c1==c2 && c1==c3) return -1;
  std::vector<Num> Num_vec;
  std::vector<char> op_vec;
  int Num_size = Num_vec.size();
  Num ans(Num_vec[0]);
  for (auto i = 1;i < Num_size;++i) {
    ans = op(ans, Num_vec[i], op_vec[i-1]);
  }
  return ans.to_int();
}

int main(int argc, char** argv) {
  std::vector<char> op {'+', '-', '*', '/', '~'};
  for (int i = 1000;i < 10000;++i) {
    for (auto e : op) {
      for (auto f : op) {
        for (auto g : op) {
          if (eval(i, e, f, g) == i) {
            std::cout << i << '\n';
            return 0;
          }
        }
      }
    }
  }
}
