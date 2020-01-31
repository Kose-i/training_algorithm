#include <iostream>
#include <vector>
#include <utility>

constexpr int mod {1000000007};
constexpr int Max_num {100000+1};

using P = std::pair<unsigned, unsigned>;

struct mint {
  long long x;
  mint(ll x =0) : x((x%mod+mod)%mod) {}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  //for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    mint res(*this);
    return res /= a;
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

class Prime_Decomposition{
  public:
  Prime_Decomposition() {
    get_prime();
  }
  std::vector<P> decomposition(long long a) {
    std::vector<P> num_prime_decomposition;
    for (auto i = 0;i < Max_num;++i) {
      if (a == 1) break;
      if (a % prime_box[i] == 0) {
        P t;
        t.first = prime_box[i];
        t.second = 0;
        for (;a % prime_box[i] == 0;a /= prime_box[i]) {
          ++t.second;
        }
        num_prime_decomposition.push_back(t);
      }
    }
    return num_prime_decomposition;
  }
  private:
  void get_prime() {
    std::bitset<Max_num> bi;
    bi.flip();
    bi[0] = bi[1] = 0;
    for (auto i = 0;i < Max_num;++i) {
      if (bit_prime[i] == 0) continue;
      for (auto j = i+i;j < Max_num;j += i) {
        bit_prime[j] = 0;
      }
    }
    for (auto i = 0;i < Max_num;++i) {
      if (bit_prime[i] == 1) prime_box.push_back(i);
    }
  }
  std::vector<unsigned> prime_box;
};
int main(int argc, char** argv) {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  for (auto& e : A) std::cin >> e;
}
