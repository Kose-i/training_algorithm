#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

#define maxs(x,y) (x=std::max(x,y))
#define mins(x,y) (x=std::min(x,y))

struct P {
  ll x, y;
};

typedef *Node Path;
typedef struct Node {
  int number;
  vector<Path> Path_box;
};

int main() {
  ll N;
  cin >> N;
  vector<vector<char>> board(N, vector<char>(N, 4));
  rep(i, N-1) {
    int x, y;
    cin >> x >> y;
    board[x-1][y-1] = 1;
  }
  vector<P> tree; // Restrain
}
