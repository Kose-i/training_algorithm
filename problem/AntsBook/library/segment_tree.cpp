#include <vector>
#include <cmath>
/***
**** index
****                     0
****                1          2
****             3    4     5     6
****            7 8  9 10 11 12 13 14
****
****    -> V = 8
*/

class Segment_tree{
  private:
    const int N;
    const int node_size;
    std::vector<int> dat;
    constexpr static int null_val {0};
    int query_helper(const int& a, const int& b, const int& k, const int& l, const int& r) {
      if (r <= a || b <= l) return null_val;
      if (a <= l && r <= b) return dat[k];
      else {
        int vl = query(a, b, k*2+1, l, (l+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        return std::min(vl, vr);
      }
    }
  public:
    Segment_tree(const int& V) : N(V) {
      int n = 1;
      while (n < N) n *= 2;
      node_size = 2*n -1;
      dat.reserve(node_size);
      for (auto i = 0;i < node_size;++i) dat[i] = null_val;
    }
    void update(int index, const int& val) {
      int k = node_size - (node_size+1)/2 + index;
      dat[k] = val;
      while (k > 0) {
        k = (k - 1) / 2;
        dat[k] = std::min(dat[k*2 + 1], dat[k*2 + 2]);
      }
    }
    int query(const int left, const int right) {
      return query_helper(left, right, 0, 0, (node_size+1)/2);
    }
};
