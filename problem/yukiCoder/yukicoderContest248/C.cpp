#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stdio.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF
constexpr int INTINF {1000000000};//int = 2*INTINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T&& y) {
  x=std::max(x,y);
}
template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T&& y) {
  x=std::min(x,y);
}
template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

struct Query{
  int t, a, b;
};

struct Node {
  ull number;
  unsigned parent; // parent == 0 => not exist
};
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q_cnt;
  scanf("%d%d", &n, &q_cnt);
  vector<Query> X(q_cnt);
  rep(i, q_cnt) {
    scanf("%d%d%d", &X[i].t, &X[i].a, &X[i].b);
  }

  vector<Node> Party(n+1);
  rep(i, n+1) {
    Party[i].number = 0;
    Party[i].parent = 0;
  }
  int Parent_size {n};
  rep(i, q_cnt) {
    if (X[i].t == 1) {
      Node tmp;
      tmp.number = 0; tmp.parent = 0;
      Party.push_back(tmp);
      ++Parent_size;
      int index {X[i].a};
      while (Party[index].parent!=0) index = Party[index].parent;
      Party[index].parent = Parent_size;
      index = X[i].b;
      while (Party[index].parent!=0) index = Party[index].parent;
      Party[index].parent = Parent_size;
    } else if (X[i].t == 2) {
      int index {X[i].a};
      while (Party[index].parent!=0) index = Party[index].parent;
      Party[index].number += X[i].b;
    } else {//X[i].t == 3
      int ans {};
      int index {X[i].a};
      do {
        ans  += Party[index].number;
        index = Party[index].parent;
      } while (index != 0);
      cout << ans << '\n';
    }
  }
}
