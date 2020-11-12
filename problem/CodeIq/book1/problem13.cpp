/*
READ + WRITE + TALK = SKILL
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool find_answer(const std::vector<int>& permutation) {
/*
READ + WRITE + TALK = SKILL
0123   40561   6278   98577
*/
  if (permutation[0] == 0 || permutation[4] == 0 || permutation[6] == 0 || permutation[9] == 0) return false;
  int read {1000*permutation[0] + 100*permutation[1] + 10*permutation[2]+permutation[3]};
  int write {10000*permutation[4] + 1000*permutation[0] + 100*permutation[5] + 10*permutation[6] + permutation[1]};
  int talk {1000*permutation[6] + 100*permutation[2] + 10*permutation[7] + permutation[8]};
  int skill {10000*permutation[9] + 1000*permutation[8] + 100*permutation[5] + 10*permutation[7] + permutation[7]};

  if (read + write + talk == skill) {
    std::cout << read << '+' << write << '+' << talk << '=' << skill << '\n';
    return true;
  }
  return false;
}

int main(int argc, char** argv) {
  std::vector<int> permutation(10);
  for (auto i = 0;i < 10;++i) permutation[i] = i;

  int cnt {};
  do {
    if (find_answer(permutation)) {
      ++cnt;
    }
  }while(std::next_permutation(permutation.begin(), permutation.end()));
  std::cout << "cnt:" << cnt << '\n';
}
