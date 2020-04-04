#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <list>

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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, K, C;
  cin >> N >> K >> C;
  vector<char> S(N);
  rep(i, N) cin >> S[i];

  std::list<int> answer_candidate;

  {
    vector<char> candidate_tmp(N, 1);
    int candidate_tmp_index {};
    for (int k_cnt = K;k_cnt != 0;--k_cnt) {
      while (candidate_tmp[candidate_tmp_index] != 1) ++candidate_tmp_index;
      answer_candidate.push_back(candidate_tmp_index);
      if (S[candidate_tmp_index] == 'x' && 2*candidate_tmp_index+1 < N) {
        candidate_tmp[2*candidate_tmp_index+1] = 0;
      }
      candidate_tmp_index += C+1;
    }
  }

  for (const auto& e : answer_candidate) {
    cout << e << ' ';
  }
  cout << '\n';

  rep(i, N) {
  }
}
