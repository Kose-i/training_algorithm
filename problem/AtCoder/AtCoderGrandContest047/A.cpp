#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <iomanip>

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


bool is_seisuu(const double& e) {
  return (e-static_cast<int>(e)==0);
}

struct ten_make {
  int ten_cnt;
  int five_cnt, two_cnt;
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long n;
  cin >> n;
  std::vector<double> a(n, 0.0);
  rep(i,n) cin >> a[i];
  auto mid = n-1;
  std::vector<int> seisuu;
  //std::vector<double> syousuu;
  std::vector<unsigned long long> syousuu_transform;
  rep(i, n) {
    if (is_seisuu(a[i])) seisuu.push_back(static_cast<int>(a[i]));
    else {
      ull tmp {static_cast<ull>(a[i])};
      a[i] -= static_cast<int>(a[i]);
      //std::cout << a[i] << ' ';
      std::stringstream ss;
      ss << std::setprecision(9) << std::fixed << a[i];
      string s = ss.str();
      //std::cout << s.size() << '\n';
      //std::cout << s << '\n';
      for (int j = 0;j < 9;++j) {
        if (s.size() <= j+2) {
          tmp *= 10;
          continue;
        } else {
          tmp *= 10;
          tmp += (int)(s[j+2]-'0');
          //std::cout << tmp << ' ';
        }
        //tmp *= 10;
        //tmp += (int)(a[i]*10);
        //a[i] *= 10;
        //a[i] -= (int)(a[i]);
      }
      //std::cout << tmp << '\n';
      syousuu_transform.push_back(tmp);
      //syousuu.push_back(a[i]);
    }
  }
  //rep(i,n) {
  //  syousuu[i] -= static_cast<int>(syousuu[i]);
  //}
  std::sort(seisuu.rbegin(), seisuu.rend());

  //rep(i, n) {
  //  if (seisuu[i] == 0) ++zero_cnt;
  //  else break;
  //}

  std::vector<std::vector<int>> search(25, std::vector<int>(17, 0));

  for (auto i = 0;i < seisuu.size();++i) {
    int two_divide {};
    while(seisuu[i] % 2 == 0) {
      ++two_divide;
      seisuu[i] /= 2;
    }
    int five_divide {};
    while(seisuu[i] % 5 == 0) {
      ++five_divide;
      seisuu[i] /= 5;
    }
    ++search[two_divide+9][five_divide+9];
  }


  for (auto i = 0;i < syousuu_transform.size();++i) {
    int two_divide {};
    while(syousuu_transform[i] % 2 == 0) {
      ++two_divide;
      syousuu_transform[i] /= 2;
    }
    int five_divide {};
    while(syousuu_transform[i] % 5 == 0) {
      ++five_divide;
      syousuu_transform[i] /= 5;
    }
    ++search[two_divide][five_divide];
  }
  //for (const auto& e : search) {
  //  for (const auto& f : e) std::cout << f << ' ';
  //  std::cout << '\n';
  //}

  std::vector<std::vector<int>> search_dp = search;
  for (auto y = 0;y < 25;++y) {
    for (auto x = 0;x < 17;++x) {
      int tmp_add {};
      for (auto i = y;i < 25;++i) {
        for (auto j = x;j < 17;++j) {
          tmp_add += search[i][j];
        }
      }
      search_dp[y][x] += tmp_add - search[y][x];
    }
  }
  //for (const auto& e : search_dp) {
  //  for (const auto& f : e) std::cout << f << ' ';
  //  std::cout << '\n';
  //}

  ull ans {};
  for (auto y = 0;y < 25;++y) {
    for (auto x = 0;x < 17;++x) {
      if (search[y][x] > 0) {
        if (18-y>=25)continue;
        if (18-x>=17)continue;
        if (y<=18-y &&x<=18-x) --ans;
        ans += search_dp[18-y][18-x];
        //std::cout << y << ' ' << x << '\n';
        //std::cout << ans << '\n';
      }
    }
  }
  std::cout << ans/2 << '\n';

  //for (const auto& e : search) {
  //  for (const auto& f : e) {
  //    std::cout << f << ' ';
  //  }
  //  std::cout << '\n';
  //}

  //for (auto & e : syousuu_transform) {
  //  std::cout << e << ' ';
  //}
  //std::cout << '\n';


}
