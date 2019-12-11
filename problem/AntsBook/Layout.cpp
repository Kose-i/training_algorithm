#include <iostream>
#include <vector>

constexpr int INF {30000};
struct data_cow{
  int number_cow1, number_cow2;
  int distance;
};

constexpr int min(int a, int b) {
  return (a<b)?a:b;
}
int answer(const int& N, const int& ML, const int& MD, const std::vector<data_cow>& like_cows, const std::vector<data_cow>& unlike_cows) {
  std::vector<int> d(N, INF);
  d[0] = 0;
  for (auto i = 0;i < N;++i) {
    for (auto j = 0; j+1 < N ;++j) {
      if (d[j+1] < INF) d[j] = min(d[j], d[j+1]);
    }
    for (auto j = 0;j < ML;++j) {
      if (d[like_cows[j].number_cow1 - 1] < INF) d[like_cows[j].number_cow2 - 1] = min(d[like_cows[j].number_cow2 - 1], d[like_cows[j].number_cow1 - 1] + like_cows[j].distance);
    }
    for (auto j = 0;j < MD;++j) {
      if (d[unlike_cows[j].number_cow2 - 1] < INF) d[unlike_cows[j].number_cow1 - 1] = min(d[unlike_cows[j].number_cow1 - 1], d[unlike_cows[j].number_cow2 - 1] - unlike_cows[j].distance);
    }
  }
  if (d[0] < 0) return -1;
  if (d[N-1] == INF) return -2;
  return d[N-1];
}
int main(int argc, char** argv) {
  const int N {4};
  const int ML {2};
  const int MD {1};
  std::vector<data_cow> like_cows;
  data_cow tmp;
  tmp.number_cow1 = 1;tmp.number_cow2 = 3;tmp.distance = 10;
  like_cows.push_back(tmp);
  tmp.number_cow1 = 2;tmp.number_cow2 = 4;tmp.distance = 20;
  like_cows.push_back(tmp);
  std::vector<data_cow> unlike_cows;
  tmp.number_cow1 = 2;tmp.number_cow2 = 3;tmp.distance = 3;
  unlike_cows.push_back(tmp);
  std::cout << answer(N, ML, MD, like_cows, unlike_cows) << '\n';
}
