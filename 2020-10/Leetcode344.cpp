#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

Solution s1;
int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    s1.reverseString(s);
    for(auto &i:s)
        cout << i << endl;
    system("pause");
    return 0;
}