#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        for(int i = 0;i < dominoes.size();i++) {
            int x = dominoes[i][0], y =  dominoes[i][1];
            if(y > x) swap(x, y);
            mp[make_pair(x, y)]++;
        }
        int ans = 0;
        for(auto &it:mp)
            if(it.second == 2)
                ans++;
        return ans;
    }
};

Solution s1;
int main() {
    vector<vector<int>> tmp = {{1,2}, {2, 1}, {3, 4}, {4, 5}};
    cout << s1.numEquivDominoPairs(tmp) << endl;
    return 0;

}