#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

bool greater(const std::pair<int, char>& lh, const std::pair<int, char>& rh) {
  return lh.first > rh.first;
}

int query(const int& x, const int& y) {
  std::cout << "? " << static_cast<char>('A'+x) << ' ' << static_cast<char>('A'+y) << '\n';
  char return_mark{};
  std::cin >> return_mark;
  if (return_mark == '>') return 1;
  else return -1;
}

void transform_table(const int& query_size, const int& table_size, std::vector<std::vector<int>>& table) {
  for (auto i = 0;i < table_size;++i) {
    for (auto j = i+1;j < table_size;++j) {
      if (table[i][j] == 0) {
        int k = query(i,j);
        table[i][j] = k;
      } // if table[i][j] == 0
    }

    for (auto j = i+1;j < table_size;++j) {
      for (auto k = j+1;k < table_size;++k) {
        if (table[i][j]*table[i][k]==-1) {
          table[j][k] = table[i][k];
        }
      }
    }
  }
}

int main(int argc, char** argv) {
  const int N {[](){int t;std::cin >> t;return t;}()};
  const int Q {[](){int t;std::cin >> t;return t;}()};
  std::vector<std::vector<int>> table;
  for (auto i = 0;i < N;++i) {
    std::vector<int> t;
    for (auto j = 0;j < N;++j) {
      t.push_back(0);
    }
    table.push_back(t);
  }

  transform_table(Q, N, table);

  std::vector<std::pair<int, char>> answer_numeric_vec;
  for (auto i = 0;i < N;++i) {
    int sum {};
    for (auto j = 0;j < i;++j) {
      sum += table[j][i];
    }
    for (auto j = i+1;j < N;++j) {
      sum -= table[i][j];
    }
    std::pair<int, char> t;
    t.first = sum;
    t.second = 'A' + i;
    answer_numeric_vec.push_back(t);
  }
  std::sort(answer_numeric_vec.begin(), answer_numeric_vec.end(), greater);

  std::cout << "! ";
  for (auto i = 0;i < N;++i) {
    std::cout << answer_numeric_vec[i].second;
  }
  std::cout << std::endl;

}
