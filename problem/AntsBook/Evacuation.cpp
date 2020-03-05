#include <vector>
#include <string>
#include <utility>
#include <map>
#include <queue>

#include "library/FordFulkerson.cpp"

struct Pos{
  int x, y;
};
Pos operator+(Pos t1, Pos t2) {
  Pos c{t1.x + t2.x, t1.y+t2.y};
  return c;
}
bool operator<(const Pos& t1, const Pos& t2) {
  return t1.x < t2.x;
}

std::vector<Pos> dir {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
const int X {5};
const int Y {12};
std::vector<std::string> map{
    {"XXXXXXXXXXXX"},
    {"X..........D"},
    {"X.XXXXXXXXXX"},
    {"X..........X"},
    {"XXXXXXXXXXXX"}
};

using Map_first = std::pair<Pos, Pos>;

void bfs(Pos pos, std::map<Pos, int>& d) {
  std::queue<Pos> q;
  d[pos] = 0;
  q.push(pos);
  while (!q.empty()) {
    pos = q.front(); q.pop();
    for (auto k = 0;k < 4;++k) {
      Pos tmp_pos = pos + dir[k];
      if (0 <= tmp_pos.x && tmp_pos.x < X && 0<=tmp_pos.y && tmp_pos.y<Y && map[tmp_pos.x][tmp_pos.y] == '.' && d[tmp_pos]<0) {
        d[tmp_pos] = d[pos] + 1;
        q.push(tmp_pos);
      }
    }
  }
}

int main(int argc, char** argv) {
  std::vector<Pos> door_pos;
  std::vector<Pos> ground_pos;
  std::map<Pos, int> d;
  for (auto x = 0;x < X;++x) {
    Pos P; P.x = x;
    for (auto y = 0;y < Y;++y) {
      P.y = y;
      if (map[x][y] == 'D') {
        door_pos.push_back(P);
        bfs(P, d);
      } else if (map[x][y] == '.') {
        ground_pos.push_back(P);
      }
    }
  }
  std::map<Map_first, int> dist;
  int d = door_pos.size(), p = ground_pos.size();
  int N = X*Y;
  for (auto i = 0;i < d;++i) {
    for (auto j = 0;j < p;++j) {
      Map_first p; p.first = door_pos[i]; p.second = ground_pos[j];
      if (dist[p] >= 0) {
        for (auto k = dist[p];k <= N;++k) {
//          add_edge((k-1)*d+i, N*d+j);
        }
      }
    }
  }
}
