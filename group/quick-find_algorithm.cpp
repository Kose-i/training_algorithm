#include <iostream>
#include <vector>
#include <string>
#include <tuple>

void make_group(std::vector<int>& number, std::vector<std::tuple<std::string,int,int>> target) {
  for(int i = 0;i < target.size();++i) {
    if(std::get<0>(target[i]) == "group") {
      if(number[std::get<1>(target[i])] != number[std::get<2>(target[i])]) {
        int t = number[std::get<1>(target[i])];
        for(int j = 0;j < number.size();++j) {
          if(number[j] == t)
            number[j] = number[std::get<2>(target[i])];
        }
      }
    } else if(std::get<0>(target[i]) == "search") {
      if(number[std::get<1>(target[i])] == number[std::get<2>(target[i])]) {
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
  std::vector<int> group(10);
  for(int i {};i < group.size();++i) {
    group[i] = i;
  }
  make_group(group,target);
}
