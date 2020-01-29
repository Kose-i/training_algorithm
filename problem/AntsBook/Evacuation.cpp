#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  const int X {5};
  const int Y {5};
  std::vector<std::vector<char>> map{
    {'X','X','D','X','X',},
    {'X','.','.','.','X',},
    {'D','.','.','.','X',},
    {'X','.','.','.','D',},
    {'X','X','X','X','X',},
  };

  for (auto x = 0;x < X;++x) {
    for (auto y = 0;y < Y;++y) {
      if (map[x][y] == 'D') {
        dx.push_back(x);
        dy.push_back(y);
        bfs(x, y, dist[x][y]);
      } else if (field[x][y] == '.') {
        px.push_back(x);
        py.push_back(y);
      }
    }
  }

  int d = dx.size();
  int p = px.size();
  for (auto i = 0;i < d;++i) {
    for (auto j = 0;j < p;++j) {
      if (dist[dx[i][dy[i]][px[j]][py[j]] >= 0) {
        for (auto k = dist[dx[i][dy[i]][px[j]][py[j]];k <= n;++k) {
          add_edge((k-1)*d + i, n*d+j);
        }
      }
    }
  }
  if (p == 0) {
    std::cout << "0\n";
    return 0;
  }
  int num {};
  std::vector<int> match(, -1);
  for (auto v = 0;v <n*d;++v) {
    if (dfs(v)) {
      if (++num == p) {
        std::cout << v/d+1 << '\n';
        return 0;
      }
    }
  }
  std::cout << "Impossible\n";
}
