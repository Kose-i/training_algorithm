#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll LLINF {1001002003004005006};//ll = 9*LLINF
constexpr int INTINF {1000000000};//int = 2*INTINF

#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

template<typename T>
void maxs(T& x, T&& y) {
  x=std::max(x,y);
}
template<typename T>
void maxs(T& x, T& y) {
  x=std::max(x,y);
}

template<typename T>
void mins(T& x, T&& y) {
  x=std::min(x,y);
}
template<typename T>
void mins(T& x, T& y) {
  x=std::min(x,y);
}

class Segment_tree{
  private:
    constexpr int null_val = 0;
    std::vector<int> data;
    int node_size;
    int query_helper(const int& left, const int& right, const int& idx, const int& split_left, const int& split_right) {
      if (left<=split_left&&split_right<=right) return data[idx];
      if (split_right<left||right<split_left) return null_val;
      int val_left = query_helper(left, (left+right)/2, idx/2)
    }
  public:
    Segment_tree(const int& V) {
      int n = 1;// 1, 2, 4, 8
      node_size = 1;
      while (n < V) {
        n *= 2;
        node_size += n;
      }
      data.reserve(node_size);
      for (auto& e : data) e = null_val;
    }
    void update(const int& node_idx, const int& value) {
      data[node_size - node_idx] = value;
      int k = node_idx * 2;
      while (k < node_size) {
        data[k] = std::max(data[k/2], data[k/2+1]);
        k *= 2;
      }
    }
    int query(const int& left, const int& right) {
      return query_helper(left, right, node_size-1, 0, node_size-1);
    }
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) {
  }
  cout << max_ans << '\n';
}
