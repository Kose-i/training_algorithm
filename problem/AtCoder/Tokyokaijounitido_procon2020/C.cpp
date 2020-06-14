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

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
//  map<int, int> A;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  vector<int> Start(N+1, 0);
  vector<int> End(N+1, 0);
  rep(j, N) {
    ++Start[max(0, j-A[j])];
    ++End[min(N, j+A[j]+1)];
  }
  rep(i, K-1) {
    int tmp {};
    vector<int> newStart = Start;
    vector<int> newEnd   = End;
    rep(j, N) {
      tmp += Start[j];
      tmp -= End[j];
      if (Start[j]>0) {
        --newStart[j];
        ++newStart[max(0, j-tmp)];
      }
      if (End[j+1]>0) {
        --newEnd[j+1];
        ++newEnd[min(N, j+1+tmp)];
      }
      //--newEnd[min(N, j+A[j]+1)];
      //++newStart[max(0, j-tmp)];
      //++newEnd[min(N, j+tmp+1)];
    }
    Start = newStart;
    End   = newEnd;
  }
  bool is_first = true;
  int tmp {};
  rep(i, N) {
    if (is_first) {
      is_first = false;
    } else {
      cout << ' ';
    }
    tmp += Start[i];
    tmp -= End[i];
    cout << tmp;
  }
  cout << '\n';

//  rep(i, K) {
//    map<int, int> B;
//    rep(j, N) {
//      for (int k = std::min(0, j-A[j]);k<=j+A[j];++k) {
//        ++B[k];
//      }
//    }
//    A = B;
//  }
//
//  bool is_first = true;
//  rep(i, N) {
//    if (is_first) {
//      is_first = false;
//    } else {
//      cout << ' ';
//    }
//    cout << A[i];
//  }
//  cout << '\n';
}
