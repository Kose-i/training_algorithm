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

bool get_value(vector<int>& Ranlengs_S, ull& ans, const int& size, const int& now_times) {
  int k {now_times};
  vector<int> Rangles_gray(size/2, 0);
  if (size % 2 == 1) {
    Rangles_gray[size/2 - 1] = (Ranlengs_S[size-1]%2==1&&k%2==0)?0:1;
    k -= Ranlengs_S[size-1];
  }
  drep(i, size/2) {
    Rangles_gray[i] = (Ranlengs_S[i+1]%2==1&&k%2==0)?0:1;
    k -= Ranlengs_S[size-1];
  }
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string S;
  cin >> S;
  
  vector<int> Ranlengs_S;
  char c = '1';
  int now_value {};
  for (const auto& e : S) {
    if (e != c) {
      Ranlengs_S.push_back(now_value);
      c = e;
      now_value = 1;
    } else {
      ++now_value;
    }
  }

  int n = S.size();
  ull ans {};
  bool is_fin {false};
  int Ranlengs_S_size {Ranlengs_S.size()};
  rep(i, n) {
    is_fin = get_value(Ranlengs_S, ans, Ranlengs_S_size, n-i);
    if (is_fin) {
      int cnt {};
      for (const auto& e : Ranlengs_S) {
        cnt += e;
      }
      ans += (cnt)*(cnt+1)/2;
      break;
    }
  }
  cout << ans << '\n';

}
