#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);++i)

int main(int argc, char** agv) {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int>> a(h, std::vector<int>(w));
    rep(i,h) {
        rep(j,w) {
            char tmp;
            std::cin>>tmp;
            a[i][j] = ((tmp=='#')?1:0);
        }
    }

    int ans {};
    rep(i, h-1) {
        rep(j, w-1) {
            if ((a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i][j+1])%2!=0) {
                ++ans;
            }
        }
    }
    std::cout << ans << '\n';
}
