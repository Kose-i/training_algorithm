#include <iostream>
#include <vector>

int sum_vector(const std::vector<int>& num) {
  int ans {};
  for (const auto& e : num) {
    ans += e;
  }
  return ans;
}

std::vector<int> add_vector(const std::vector<int>& num1, const std::vector<int>& num2) {
  // num1 < num2
  std::vector<int> num;

  int up_tmp {};
  for (auto i = 0;i < num1.size();++i) {
    num.push_back((num1[i] + num2[i] + up_tmp ) % 10);
    up_tmp = (num1[i] + num2[i] + up_tmp ) / 10;
  }
  for (auto i = num1.size();i < num2.size();++i) {
    num.push_back((num2[i]+up_tmp) % 10);
    up_tmp = (num2[i] + up_tmp ) / 10;
  }
  if (up_tmp > 0) num.push_back(up_tmp);

  return num;
}

int split(const std::vector<int>& num, const int& p) {
  int tmp {};
  for (int i = num.size() -1;0 <= i; --i) {
    int c = num[i] + 10*tmp;
    tmp = c % p;
  }
  return tmp;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& num) {
  for (int i = num.size()-1;0<=i;--i) {
    os << num[i];
  }
  os << '\n';
  return os;
}

int main(int argc, char** argv) {
  std::vector<int> number1 {1};
  std::vector<int> number2 {1};

  for (int cnt {}; cnt < 13;) {
    if (cnt > 7 && split(number1, sum_vector(number1)) == 0) {
      std::cout << number1;
      ++cnt;
    } else if (split(number1, sum_vector(number1)) == 0) {
      ++cnt;
    }
    std::vector<int> tmp_vec = add_vector(number1, number2);
    //number1 < number2
    number1 = number2;
    number2 = tmp_vec;
    //std::cout <<i+3 << ' '<< number1;
  }
}
