#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int l = 0, r = 0, len = 0, minl = 0,maxLen = INT_MAX;
        for(auto &i:t) { vis[i]++; }
        while(r < (int)s.size()) {
            if(vis[s[r]] > 0)   
                len++;
            vis[s[r]]--;
            r++;
            while(len == t.size()) {
                if(r - l < maxLen) {
                    minl = l;
                    maxLen = r - l;
                }
                if(++vis[s[l]] > 0)
                    len--;
                l++;
            }
        }
        if(maxLen == INT_MAX)
            return ans;
        else 
            return s.substr(minl, maxLen);
    }
private:
    int vis[200];
};

Solution s1;
int main() {
    cout << s1.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}