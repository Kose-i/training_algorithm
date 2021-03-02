#include <iostream>

int main(int argc, char** argv) {
    int v, t, s, d;

    std::cin >> v >> t >> s >> d;
    int min_vanish = t*v;
    int max_vanish = s*v;
    if (min_vanish <= d && d <= max_vanish) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
    }
}
