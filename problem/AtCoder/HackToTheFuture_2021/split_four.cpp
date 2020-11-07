#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stack>

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

struct Pos{
  int x, y;
};

std::string diff(const Pos& now, const Pos& next) {
  std::string ans {};
  for (int tmp = now.x; tmp < next.x;++tmp) {
    ans += 'R';
  }
  for (int tmp = now.x; next.x < tmp;--tmp) {
    ans += 'L';
  }
  for (int tmp = now.y; tmp < next.y;++tmp) {
    ans += 'D';
  }
  for (int tmp = now.y; next.y < tmp;--tmp) {
    ans += 'U';
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::vector<Pos> p(100);
  rep(i, 100) {
    cin >> p[i].y >> p[i].x;
  }
  /*
  4 split and minimum space put all
  1. 0<=x<10 && 0<=y<10 put all
  */
  std::vector<std::vector<int>> field(20, std::vector<int>(20, 0));
  rep(i, 100) {
    field[p[i].y][p[i].x] = i+1;
  }

  //std::vector<int> four_split_cnt(4, 0);
  //rep(i, 100) {
  //  four_split_cnt((p[i].x/10)+((p[i].y/10)*2));
  //}


  std::stack<int> box;
  //
  // **==
  // **==
  // ****
  // ****
  //
  rep(i, 10) cout << 'R';
  for (auto y = 0;y < 10;++y) {
    if (y % 2 == 0) {
      for (auto x = 0;x < 10;++x) {
        if (field[y][x+10] != 0) {
          box.push(field[y][x+10]);
          cout << 'I';
        }
        if (x != 9)cout << 'R';
      }
    } else {
      for (auto x = 9;0 <= x;--x) {
        if (field[y][x+10] != 0) {
          box.push(field[y][x+10]);
          cout << 'I';
        }
        if (x != 0)cout << 'L';
      }
    }
    cout << 'D';
  }
  //
  // ****
  // ****
  // **==
  // **==
  //
  for (auto y = 0;y < 10;++y) {
    if (y % 2 == 0) {
      for (auto x = 0;x < 10;++x) {
        if (field[y+10][x+10] != 0) {
          box.push(field[y+10][x+10]);
          cout << 'I';
        }
        if (x != 9)cout << 'R';
      }
    } else {
      for (auto x = 9;0 <= x;--x) {
        if (field[y+10][x+10] != 0) {
          box.push(field[y+10][x+10]);
          cout << 'I';
        }
        if (x != 0)cout << 'L';
      }
    }
    if (y != 9) cout << 'D';
  }
  cout << 'L';
  //
  // ****
  // ****
  // ==**
  // ==**
  //
  for (auto y = 9;0 <= y;--y) {
    if (y % 2 == 0) {
      for (auto x = 0;x < 10;++x) {
        if (field[y+10][x] != 0) {
          box.push(field[y+10][x]);
          cout << 'I';
        }
        if (x != 9)cout << 'R';
      }
    } else {
      for (auto x = 9;0 <= x;--x) {
        if (field[y+10][x] != 0) {
          box.push(field[y+10][x]);
          cout << 'I';
        }
        if (x != 0)cout << 'L';
      }
    }
    cout << 'U';
  }
  // Putting
  // ==**
  // ==**
  // ****
  // ****
  //
  for (auto y = 9;0 <= y;--y) {
    if (y % 2 == 0) {
      for (auto x = 0;x < 10;++x) {
        if (field[y][x] == 0) {
          field[y][x] = box.top();
          box.pop();
          cout << 'O';
        }
        if (x != 9)cout << 'R';
      }
    } else {
      for (auto x = 9;0 <= x;--x) {
        if (field[y][x] == 0) {
          field[y][x] = box.top();
          box.pop();
          cout << 'O';
        }
        if (x!=0)cout << 'L';
      }
    }
    if (y != 0) cout << 'U';
  }
  //rep(i, 9) cout << 'L';

  if (box.size() != 0) return 0;


  //cout << '\n';
  for (auto y = 0;y < 10;++y) {
    for (auto x = 0;x < 10;++x) {
      Pos tmp_pos; tmp_pos.x = x; tmp_pos.y = y;
      //cout << field[y][x] << ' ';
      p[field[y][x]-1] = tmp_pos;
    }
    //cout << '\n';
  }
  Pos now_pos; now_pos.x = 9; now_pos.y = 0;
  rep(i, 100) {
    std::cout << diff(now_pos, p[i]) << 'I';
    now_pos = p[i];
  }
  cout << '\n';

}
