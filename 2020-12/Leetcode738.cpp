#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 0;
        while(i < s.size() && s[i] <= s[i+1])
            i++;
        if(i < s.size()-1) {
            s[i] = s[i] - 1;
            while(i >= 0 && s[i-1] > s[i]) {
                s[i-1] -= 1;
                i--;
            }
            i++;
            while(i < s.size()) {
                s[i] = '9';
                i++;
            }
        }
        return stoi(s);
    }
};

Solution s1;
int main() {
    cout << s1.monotoneIncreasingDigits(332) << endl;
    return 0;
}