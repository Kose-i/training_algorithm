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

  ull N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<string> S(N);
  rep(i, N) cin >> S[i];

  bool is_ok = true;
  vector<char> ans_vec(N);
  if (A + B + C == 0) {
    is_ok = false;
  } else if (A + B + C==1) {
    rep(i, N) {
      if (S[i] == "AB") {
        if (A == 1) {
          ans_vec[i] = 'B';
          B = 1;
          A = 0;
        } else if (B==1) {
          ans_vec[i] = 'A';
          A = 1;
          B = 0;
        } else {
          is_ok = false;
          break;
        }
      } else if (S[i] == "AC") {
        if (A==1) {
          ans_vec[i] = 'C';
          A = 0;
          C = 1;
        } else if (C==1) {
          ans_vec[i] = 'A';
          A = 1;
          C = 0;
        } else {
          is_ok = false;
          break;
        }
      } else { //BC
        if (B==1) {
          ans_vec[i] = 'C';
          B = 0;
          C = 1;
        } else if (C==1) {
          ans_vec[i] = 'B';
          B = 1;
          C = 0;
        } else {
          is_ok = false;
          break;
        }
      }
    }
  } else {//A+B+C>=2
    if (A == 0 && B == 0 && S[0] == "AB") {
      is_ok = false;
    } else if (A == 0 && C == 0 && S[0]=="AC") {
      is_ok = false;
    } else if (B == 0 && C == 0 && S[0] == "BC") {
      is_ok = false;
    } else {
      rep(i, N) {
        if (A == 0 && (S[i] == "AB" || S[i] == "AC")) {
          ans_vec[i] = 'A';
          A = 1;
          if (S[i] == "AB") --B;
          else --C;//S[i] == "AC"
        } else if (B==0 && (S[i]=="AB" || S[i] =="BC")) {
          ans_vec[i] = 'B';
          B = 1;
          if (S[i] == "AB") --A;
          else --C;
        } else if (C==0 && (S[i]=="AC"||S[i]=="BC")) {
          ans_vec[i] = 'C';
          C = 1;
          if (S[i]=="AC") --A;
          else --B;
        } else if (i == N-1) {
          ans_vec[i] = S[i][0];
        } else {
          if (S[i]=="AC") {
            if (find(S[i+1].begin(), S[i+1].end(), 'A')!=S[i+1].end()) {
              ans_vec[i] = 'A';
              ++A;
              --C;
            } else {
              ans_vec[i] = 'C';
              ++C;
              --A;
            }
          } else if (S[i]=="AB") {
            if (find(S[i+1].begin(), S[i+1].end(), 'A')!=S[i+1].end()) {
              ans_vec[i] = 'A';
              ++A;
              --B;
            } else {
              ans_vec[i] = 'B';
              ++B;
              --A;
            }
          } else { //S[i]=="BC"
          if (find(S[i+1].begin(), S[i+1].end(), 'B')!=S[i+1].end()) {
            ans_vec[i] = 'B';
            ++B;
            --C;
          } else {
            ans_vec[i] = 'C';
            ++C;
            --B;
          }
          }
        }
      }
    }
  }

  if (is_ok == true) {
    cout << "Yes\n";
    for (const auto& e : ans_vec) {
      cout << e << '\n';
    }
  } else {
    cout << "No\n";
  }
}
