#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>

void make_group(std::vector<std::pair<int,int>>& number, std::vector<std::tuple<std::string,int,int>> target) {
  for(int i {};i < target.size();++i) {
    if(std::get<0>(target[i]) == "group") {
      int t{},m{};
      for(t = std::get<1>(target[i]);t != number[t].first ;t = number[t].first);
      for(m = std::get<2>(target[i]);m != number[m].first ;m = number[m].first);
      if(t == m) {
        continue;
      } else if(number[t].second < number[m].second) {
        number[t].second += number[m].second;
        number[t].first = m;
      } else {
        number[m].second += number[t].second;
        number[m].first = t;
      }
    } else if(std::get<0>(target[i]) == "search") {
      int t{},m{};
      for(t = std::get<1>(target[i]);t != number[t].first ;t = number[t].first);
      for(m = std::get<2>(target[i]);m != number[m].first ;m = number[m].first);
      if(t == m) {
        std::cout << "same group\n";
      } else {
        std::cout << "not same group\n";
      }
    }
  }
}

int main(int argc, char** argv) {
  std::vector<std::tuple<std::string,int,int>> target(10);
  target[0] = std::make_tuple("group",1,3);
  target[1] = std::make_tuple("group",5,2);
  target[2] = std::make_tuple("group",4,7);
  target[3] = std::make_tuple("group",8,5);
  target[4] = std::make_tuple("group",3,9);
  target[5] = std::make_tuple("group",7,4);
  target[6] = std::make_tuple("group",2,3);
  target[7] = std::make_tuple("group",3,3);
  target[8] = std::make_tuple("group",2,6);
  target[9] = std::make_tuple("search",4,5);
  std::vector<std::pair<int,int>> group(10);
  for(int i {};i < group.size();++i) {
    group[i].first = i;
    group[i].second = 1;
  }
  make_group(group,target);
}
