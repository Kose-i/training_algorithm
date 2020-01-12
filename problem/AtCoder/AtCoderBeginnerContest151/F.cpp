#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
struct Point{
  int x, y;
};

constexpr int max(int a, int b) {
  return (a>b)?a:b;
}
constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
std::istream& operator>>(std::istream& is, Point& p) {
  return is>>p.x >> p.y;
}

int main(int argc, char** argv) {
  int N; cin >> N;
  vector<Point> pos_vec(N);
  for (auto& e : pos_vec) cin >> e;
  int min_x, max_x, min_y, max_y;
  min_x = pos_vec[0].x; max_x = pos_vec[0].x;
  min_y = pos_vec[0].y; max_y = pos_vec[0].y;
  for (auto& e : pos_vec) {
    min_x = min(e.x, min_x);
    max_x = max(e.x, max_x);
    min_y = min(e.y, min_y);
    max_y = max(e.y, max_y);
  }
  cout << std::sqrt((max_x - min_x)*(max_x - min_x) + (max_y - min_y)*(max_y - min_y)) << '\n';
}
