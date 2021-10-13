#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    set<int> se;
    se.insert(0);

    int sum {};
    for (int i=0;i<n;++i) {
        sum += a[i];
        set<int> new_se;
        for (const int& e : se) {
            new_se.insert(std::abs(e - a[i]));
            new_se.insert(e + a[i]);
        }
        se = new_se;
    }
    cout << (sum + *se.begin()) / 2<< '\n';
}
