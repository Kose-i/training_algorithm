#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv) {
  int N;
  std::string S;
  std::cin >> N >> S;
  std::vector<std::string> matches;
  for (auto i = 0;i < N-2;++i) {
    for (auto j = i+1;j < N-1;++j) {
      for (auto k = j+1;k < N;++k) {
        std::string s = "000";
        s[0] = S[i];
        s[1] = S[j];
        s[2] = S[k];
        if (std::find(matches.begin(), matches.end(), s) == matches.end()) {
          matches.push_back(s);
        }
      }
    }
  }
  std::cout << matches.size() << '\n';
}
