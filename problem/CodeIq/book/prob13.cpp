#include <iostream>
#include <vector>

namespace prob13{
  const int M {9};
  const int N {5};
  //seq:カードのセット状況
  //used: 使用済みのカード(ビット列)
  //n: 残りの移動回数
  unsigned search(std::vector<int>& seq, const int& used, const int& n) {
    if (n==0) {
      int res = 1;
      int cnt = [&](){
        int sum{};
        for(const auto&e: seq)if(e==0)++sum;
        return sum;
      }();
      for (auto i = 1;i <= cnt;++i) {
        res *= i;
      }
      return res;
    }
    int cnt {0};
    for (auto i = 1;i < M;++i) {
      std::vector<int> new_seq = seq;
      for (auto j=0;j < i+1;++j) {
        new_seq[j] = seq[i - j];
      }
      if ((seq[i]==0)&&(used & (1<<i))==0){
        new_seq[0] = i+1;
        cnt += search(new_seq, used|(1<<i), n-1);
      } else if (seq[i]==i+1) {
        cnt += search(new_seq, used, n-1);
      }
    }
    return cnt;
  }
  unsigned long answer() {
    std::vector<int> seq(M, 0);
    seq[0] = 1;
    unsigned que_cnt = search(seq, 1, N);
    return que_cnt;
  }
}

int main(int argc, char** argv) {
  std::cout << prob13::answer() << '\n';
}
