#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);++i)

int main(int argc, char** argv) {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    rep(i, n) std::cin >> a[i];

    bool first {true};
    rep(i,n) {
        if (a[i] == x) continue;
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }
        std::cout << a[i];
    }
    std::cout << '\n';
}
