#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    string ans;
    int now_alphabets {};
    vector<int> alphabets_list;
    for (int i=0;i<n;++i) {
        cout << "? 2 1 " << i+1 << std::endl;
        int num;
        cin >> num;
        if (num != now_alphabets) {
            ++now_alphabets;
            char c;
            cout << "? 1 " << i+1 << std::endl;
            cin >> c;
            ans += c;
            alphabets_list.push_back(i);
        } else { // num == now_alphabets O(log_2 (26) < 5)
            int left {}, right = alphabets_list.size()-1;
            for (;left<right;) {
                cout << left << '-' << right << '\n';
                int mid = (left+right+1)/2;
                int index = alphabets_list[mid];
                cout << "? 2 " << index +1 << ' ' << i+1 << std::endl;
                cin >> num;
                map<char, int> mp;
                for (int j=index;j<ans.size();++j) ++mp[ans[j]];
                if (mp.size() != num) right = mid;
                else left = mid;
            }
            ans += ans[alphabets_list[left]];
        }
    }
    cout << "! " << ans << std::endl;
}
