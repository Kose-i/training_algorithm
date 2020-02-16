#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#define rep(i, n) for(int i = 0;i < (n);++i)
using ll = long long;

struct P {
  std::string S;
  ll num;
};
bool P_comp(P& l, P& r) {
  return l.num > r.num;
}

int main(int argc, char** argv) {
  ll N;
  std::cin >> N;
  std::vector<std::string> S(N);
  rep(i, N) std::cin >> S[i];
  std::sort(S.begin(), S.end());
  std::string prev_s = "";
  std::vector<P> S_box;
  ll dim {-1};
  for (auto i = 0;i < N;++i) {
    if (prev_s != S[i]) {
      P tmp;
      tmp.S = S[i]; tmp.num = 1;
      prev_s = S[i];
      S_box.push_back(tmp);
      ++dim;
    } else {
      ++S_box[dim].num;
    }
  }
  std::sort(S_box.begin(), S_box.end(), P_comp);
  int max_num = S_box[0].num;
  std::vector<std::string> S_sorted;
  for (auto i = 0;i <= dim;++i) {
    if (S_box[i].num == max_num) S_sorted.push_back(S_box[i].S);
    else break;
  }
  std::sort(S_sorted.begin(), S_sorted.end());
  for (auto& e : S_sorted) std::cout << e << '\n';
}
