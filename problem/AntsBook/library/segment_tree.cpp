#include <vector>
#include <cmath>

class Segment_tree{
  private:
    constexpr static int INF {1000000000};
    const int N;
    std::vector<int> dat;
  public:
    Segment_tree(const int& V, const std::vector<int>& data) : N(V), dat(data) {
      int n = 1;
      while (n < N) n *= 2;
      for (auto i = 0;i < 2*n - 1;++i) dat[i] = INF;
    }
    void update(int k, const int& a) {
      k += N - 1;
      dat[k] = a;
      while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = std::min(dat[k*2 + 1], dat[k*2 + 2]);
      }
    }
    int query(const int a, const int b, const int k, const int l, const int r) {
      if (r <= a || b <= l) return INF;
      if (a <= l && r <= b) return dat[k];
      else {
        int vl = query(a, b, k*2+1, l, (l+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        return std::min(vl, vr);
      }
    }
};
