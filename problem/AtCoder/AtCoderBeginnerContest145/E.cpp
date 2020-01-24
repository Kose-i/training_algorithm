#include <iostream>
#include <queue>
#include <vector>

struct P{
  int A, B;
};

struct Timetable{
  int time = 0;
  int get_score = 0;
  int max_time = 0;
};

constexpr int max(int a, int b) {
  return (a<b)?b:a;
}
int main(int argc, char** argv) {
  int N, T;
  std::cin >> N >> T;
  std::vector<P> Food(N);
  for (auto& e : Food) {
    std::cin >> e.A >> e.B;
  }
  Timetable null_Timetable;
  std::queue<Timetable> queue;
  queue.push(null_Timetable);
  for (int i = 0;i < N;++i) {
    int size_queue = queue.size();
    for (int j = 0;j < size_queue;++j) {
      Timetable null_Timetable = queue.front();
      queue.pop();
      if (null_Timetable.time - null_Timetable.max_time > T) {
        continue;
      }
      queue.push(null_Timetable);
      null_Timetable.time += Food[i].A;
      null_Timetable.get_score += Food[i].B;
      null_Timetable.max_time = max(null_Timetable.max_time, Food[i].A);
      queue.push(null_Timetable);
    }
  }
  int max_score {};
  int size_queue = queue.size();
  for (int j = 0;j < size_queue;++j) {
    Timetable null_Timetable = queue.front();
    queue.pop();
    if (null_Timetable.time - null_Timetable.max_time > T) {
      continue;
    }
    max_score = max(max_score, null_Timetable.get_score);
  }
  std::cout << max_score << '\n';
}
