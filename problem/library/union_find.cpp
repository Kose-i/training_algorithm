#include <iostream>
#include <vector>

class UnionFind {
  private:
    int node_size;
    std::vector<int> data; // data[0] is not used
  public:
    UnionFind(const int& n=0) : node_size(n+1), data(n+1) {
      for (auto i = 0;i < n+1;++i) {
        data[i] = i;
      }
    }
    int find(const int& x) {
      if (x == data[x]) return x;
      return data[x] = find(data[x]);
    }
    bool unite(int x, int y) {
      x = find(x); y = find(y);
      if (x==y) return false;// is already grooped
      if (data[x] > data[y]) { // swap x<->y
        int tmp = x;
        x = y;
        y = tmp;
      }
      //data[x] += data[y];
      data[y] = x;
      return true;
    }
    bool same(const int& x, const int& y) {
      return (find(x)==find(y));
    }
    int size(const int& x) {
      return -data[find(x)];
    }
};

//int main(int argc, char** argv) {
//  UnionFind uf(5);
//  //group 1 2
//  uf.unite(1, 2);
//  //search 3 4
//  if (uf.same(3,4)) std::cout << "is-group\n";
//  else std::cout << "not-group\n";
//  //group 4 5
//  uf.unite(4,5);
//  //group 3 4
//  uf.unite(3,4);
//  //search 3 5
//  if (uf.same(3,5)) std::cout << "is-group\n";
//  else std::cout << "not-group\n";
//}
