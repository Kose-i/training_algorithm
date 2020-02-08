#include <vector>

class BinaryIndexedTree{
  private:
    std::vector<int> bit;
    const int N;
  public:
    BinaryIndexedTree(const int& n) : bit(n, 0), N(n) {}
    int sum(int i) {
      int s {};
      while (i > 0) {
        s = bit[i];
        i -= (i&(-i));
      }
      return s;
    }
    void add(int i, int x) {
      while (i <= N) {
        bit[i] += x;
        i += (i&(-i));
      }
    }
};
