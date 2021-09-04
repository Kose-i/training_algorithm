#include <iostream>
#include <vector>
#include <utility>

using Pair = std::pair<int, int>;

int main() {
    const int x_size {1000};
    const int y_size {1000};

    std::vector<std::vector<int>> table(y_size, std::vector<int>(x_size, 0));
    int n {5};
    std::vector<Pair> lt {{1, 1},     {10, 20},   {30, 30},  {40, 10}, {10, 80}};
    std::vector<Pair> rb {{500, 100}, {400, 500}, {100, 32}, {42,180}, {100, 200}};

    for (int i=0;i<n;++i) {
        ++table[lt[i].first][lt[i].second];
        --table[lt[i].first][rb[i].second+1];
        --table[rb[i].first+1][lt[i].second];
        ++table[rb[i].first+1][rb[i].second+1];
    }

    for (int y=0;y<y_size;++y) {
        for (int x=0;x<x_size;++x) {
            if (y!= 0) table[y][x] += table[y-1][x];
        }
    }
    for (int y=0;y<y_size;++y) {
        for (int x=0;x<x_size;++x) {
            if (x!= 0) table[y][x] += table[y][x-1];
        }
    }

    int max_val {table[0][0]};
    for (int y=0;y<y_size;++y) {
        for (int x=0;x<x_size;++x) {
            if (max_val < table[y][x]) max_val = table[y][x];
        }
    }
    std::cout << max_val << '\n';
}
