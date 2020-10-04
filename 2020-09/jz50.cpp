#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if(s.empty())
            return ' ';
        for(int i = 0;i < s.size();i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int min_pos = INT_MAX;
        char ans = s[0];
        for(int i = 0;i < 26;i++) {
            if(pos[i].size() == 1) {
                if(pos[i][0] < min_pos) {
                    min_pos = pos[i][0];
                    ans = char(i + 'a');
                }
            }
        }
        if(min_pos == INT_MAX)
            return ' ';
        return ans;
    }
private:
    vector<int> pos[26];
};

Solution s1;
int main(){
    cout << s1.firstUniqChar("abaccdeff");
    system("pause");
    return 0;
}