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

int get_ketasuu(const ull& t) {
    int ans {};
    for (ull tmp = t;tmp!=0;++ans) tmp /= 10;
    return ans;

}
int saijoui(const ull& t) {
    int c {};
    for (ull tmp = t;tmp != 0;tmp /= 10) c = tmp%10;
    return c;
}
ull del_saijoui(const ull& t) {
    ull tmp = saijoui(t);
    for (;tmp*10 <= t;tmp*=10);
    return t - tmp;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ull target_num;
  cin >> target_num;

  int ketasuu_target_num {get_ketasuu(target_num)};
  std::vector<ull> a(ketasuu_target_num+1, 0);
  std::vector<ull> b(ketasuu_target_num+1, 0);
  for (int i=1;i<=ketasuu_target_num;++i) {
    a[i] = a[i-1]*10+1;
    b[i] = b[i-1] + a[i];
  }

  ull ans {b[get_ketasuu(target_num/10)]};
  for (ull tmp = target_num;tmp != 0;) {
    int saijoui_num = saijoui(tmp);
    if (saijoui_num == 1) {
        int c = get_ketasuu(tmp);
        tmp = del_saijoui(tmp);
        ans += (tmp+1);
        if (c != get_ketasuu(tmp)+1) break;
    } else {
        //cout << ans << "---" << tmp << '\n';
        ans += a[get_ketasuu(tmp)];
        break;
    }
  }
  cout << ans << '\n';
}
