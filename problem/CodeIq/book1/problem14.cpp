#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int search(std::vector<char> is_flag, const std::vector<std::vector<int>>& box, int prev_idx) {
  int max_ans {};
  for (auto i = 0;i < box.size();++i) {
    if (is_flag[i] == 0 && box[prev_idx][i] == 1) {
      is_flag[i] = 1;
      int tmp = search(is_flag, box, i) + 1;
      if (max_ans < tmp) max_ans = tmp;
      is_flag[i] = 0;
    }
  }
  return max_ans;
}
int max_search(const std::vector<char>& is_flag, const std::vector<std::string>& countries_name) {

  int max_ans {};
  std::vector<std::vector<int>> box(countries_name.size(), std::vector<int>(countries_name.size(), 0));
  for (auto i = 0;i < countries_name.size();++i) {
    for (auto j = 0;j < countries_name.size();++j) {
      if (i == j) continue;
      if (countries_name[i][countries_name[i].size()-1]==countries_name[j][0]) {
        box[i][j] = 1;
      }
    }
  }
  for (auto i = 0;i < countries_name.size();++i) {
    int tmp = search(is_flag, box, i) + 1;
    if (tmp > max_ans) max_ans = tmp;
  }
  return max_ans;
}
int main(int argc, char** argv) {
  std::vector<std::string> countries_name {
    "Brazil", "Croatia", "Mexico", "Cameroon", "Spain", "Netherlands",
    "Chile", "Austraria", "Colombia", "Greece", "Cote d'lvoire", "Japan", 
    "Uruguay", "Costa Rica", "England", "Italy", "Switzerland", "Ecuador",
    "France", "Honduras", "Argentina", "Bosnia and Herzegovina", "Iran", "Nigeria",
    "Germany", "Portugal", "Ghana", "USA", "Belgium", "Algeria", "Russia", "Korea Republic"
  };


  int c = static_cast<int>('a') - static_cast<int>('A');
  // A < a
  if (c < 0) {
    std::cout << "a < A\n";
    return -1;
  }

  for (auto& e : countries_name) {
    for (auto& f : e) {
      if (f == ' ') continue;
      if (f < 'a') f = f + c;
    }
  }
  //for (const auto& e : countries_name) {
  //  std::cout << e << '\n';
  //}

  std::vector<char> is_flag(countries_name.size(), 0);
  std::cout << max_search(is_flag, countries_name) << '\n';
}
