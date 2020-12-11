#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string s) {
        string D = "Dire", R = "Radiant";
        queue<int> radiant, dire;
        int n = s.size();
        for (int i = 0;i < n;i++) {
            if(s[i] == 'D')
                dire.push(i);
            else 
                radiant.push(i);
        }
        while(!radiant.empty() && !dire.empty()) {
            if(radiant.front() < dire.front()) {
                radiant.push(radiant.front() + n);
            } else {
                dire.push(dire.front() + n);
            }
            radiant.pop();
            dire.pop();
        }
        if(radiant.empty())
            return D;
        return R;
    }
};

Solution s1;
int main() {
    cout << s1.predictPartyVictory("RRD") << endl;
    return 0;
}