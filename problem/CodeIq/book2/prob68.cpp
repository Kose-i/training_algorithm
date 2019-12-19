#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

namespace prob68{
  std::string operator+(std::string s, char& c) {
    std::string str = s;
    str += c;
    return str;
  }
  std::vector<std::string> split()
  unsigned search(const int& n, const int& N,  bool flag, std::string left, std::string right, const std::vector<std::string>& l, const std::string& c, const std::vector<std::string>& r) {
    if (n == 0) {
      std::vector<std::string> array = (left + right).split("");
      uniq = std::for_each(array.begin(), array.end(), []())
      return (uniq.size() == N)?1:0;
    }
    unsigned cnt {};
    for (auto i = 0;i < c.size(); ++i) {
      for (auto j = 0;j < l[i].size(); ++j) {
        if (flag) {
          cnt += search(n-1, N, !flag, left+l[i][j], c[i]+r[i][j]+right, l,c,r)
        } else {
          cnt += search(n-1, N, !flag, left + c[i]+r[i][j], l[i][j]+right, l,c,r);
        }
      }
    }
    return cnt;
  }
  unsigned answer(const int& N) {
    std::vector<std::string> l {"DHLPTXdh", "AEIMQUYaei", "BFJNRVZbfj"};
    std::string c {"QUY"};
    std::vector<std::string> r {"QRSTUVYZ", "PQRSTUVXYZ", "PQRSTUVXYZ"};
    return search(N,N, true, "", "", l, c, r);
  }
}

int main(int argc, char** argv) {
  const int n {5};
  std::cout << prob68::answer(n) << '\n';
}
