#include <iostream>
#include <array>
#include <algorithm>

namespace prob10{
  constexpr std::array<unsigned, 47> poplations{
    5381733,1308265,1279594,2333899,1023119,1123891,
    1914039,2916976,1974255,1973115,7266534,6222666,
    13515271,9126214,2304264,1066328,1154008,786740,
    834930,2098804,2031903,3700305,7483128,1815865,
    1412916,2610353,8839469,5534800,1364316,963579,
    573441,694352,1921525,2843990,1404729,755733,
    976263,1385262,728276,5101556,832832,1377187,
    1786170,1166338,1104069,1648177,1433566
  };
  constexpr auto ans_chairs = 289;
  std::array<unsigned, 47> make_chair_box(const unsigned& min, const unsigned& max){
    if (min == max) {
      std::array<unsigned, 47> array_ans{};
      for (auto i = 0;i < 47;++i) {
        array_ans[i] = (poplations[i] / min) + ((poplations[i] % min > 0)?1:0);
      }
      return array_ans;
    }
    unsigned ave = (min + max) / 2;
    unsigned sum_chairs {};
    std::for_each(poplations.begin(), poplations.end(), [&](const auto& e){sum_chairs += (e / ave) + ((e % ave > 0)?1:0);});
    if (sum_chairs > ans_chairs) {
      if (min == ave) {
        return make_chair_box(max, max);
      } else {
        return make_chair_box(ave, max);
      }
    } else {
      if (max == ave) {
        return make_chair_box(min, min);
      } else {
        return make_chair_box(min, ave);
      }
    }
  }
  std::array<unsigned, 47> answer(){
    unsigned tmp_poplations = prob10::poplations[0];
    std::array<unsigned, 47> chairs_box = make_chair_box(1, tmp_poplations);
    return chairs_box;
  }
}

int main(int argc, char** argv) {
  auto vec_ans = prob10::answer();
  for (const auto& e : vec_ans) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
