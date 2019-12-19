#include <iostream>
#include <vector>
#include <algorithm>

namespace prob5{
  class Pascal_triangle{
    private:
      std::vector<unsigned long long> pascal_triangle_cols;
      std::vector<unsigned> units_coins{10000, 5000, 2000, 1000, 500, 100, 50, 10, 5, 1};
    public:
      Pascal_triangle():pascal_triangle_cols{1}
      {};
      inline void make_next_cols() {
        std::vector<unsigned long long> tmp_pascal_now = pascal_triangle_cols;
        for (auto i = 1;i < pascal_triangle_cols.size();++i) {
          pascal_triangle_cols[i] = tmp_pascal_now[i] + tmp_pascal_now[i - 1];
        }
        pascal_triangle_cols.push_back(1);
      }
      void make_cols(const unsigned long& cols) {
        for (auto i = 0;i < cols;++i) {
          make_next_cols();
        }
      }
      void print_pascal_cols() {
        for (auto e : pascal_triangle_cols) {
          std::cout << e << ' ';
        }
        std::cout << '\n';
      }
      std::vector<unsigned long> make_min_coins() {
        std::vector<unsigned long> min_coins_tmp(pascal_triangle_cols.size());
        for (auto i = 0; i < pascal_triangle_cols.size(); ++i) {
          unsigned long long tmp_pascal_one_elem = pascal_triangle_cols[i];
          for (const auto& e : units_coins) {
            min_coins_tmp[i] += tmp_pascal_one_elem / e;
            tmp_pascal_one_elem %= e;
          }
        }
        return min_coins_tmp;
      }
      unsigned long long answer(const unsigned long& cols) {
        make_cols(cols);
        std::vector<unsigned long> used_count_coins = make_min_coins();
        unsigned long long ans_tmp {};
        std::for_each(used_count_coins.begin(), used_count_coins.end(), [&ans_tmp](const auto& e){ans_tmp+=e;});
        return ans_tmp;
      }
  };
}

int main(int argc, char** argv) {
  prob5::Pascal_triangle tmp;
  std::cout << tmp.answer(45) << '\n';
}
