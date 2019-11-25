#include <iostream>
#include <vector>
#include <string>

struct TimeTable{
  int t;
  int x;
  int y;
};

bool error_table(const TimeTable& diff_table) {
  int diff = (diff_table.x < 0)?-diff_table.x:diff_table.x;
  diff    += (diff_table.y < 0)?-diff_table.y:diff_table.y;
  int k = diff_table.t - diff;
  if (k < 0 || k%2!=0) return true;
  return false;
}
std::string answer(const unsigned& size, const std::vector<TimeTable>& timetable) {
  for (auto i = 1;i < size;++i) {
    TimeTable diff_time_pos;
    diff_time_pos.t = timetable[i].t - timetable[i-1].t;
    diff_time_pos.x = timetable[i].x - timetable[i-1].x;
    diff_time_pos.y = timetable[i].y - timetable[i-1].y;
    if (error_table(diff_time_pos)) return "No";
  }
  return "Yes";
}

int main(int argc, char** argv) {
  const unsigned size{[](){unsigned t;std::cin>> t;return t;}()};
  std::vector<TimeTable> pos_timetable;
  TimeTable p;
  p.t = 0;
  p.x = 0;
  p.y = 0;
  pos_timetable.push_back(p);
  for (auto i = 0;i < size;++i) {
    std::cin >> p.t >> p.x >> p.y;
    pos_timetable.push_back(p);
  }
  std::cout << answer(size+1, pos_timetable) << '\n';
}
