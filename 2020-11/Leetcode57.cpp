#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>& insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr),cout.tie(nullptr);
        int L = newInterval[0], R = newInterval[1];
        bool flag = false;
        for(int i = 0;i < intervals.size();i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if(l > R) {
                if(!flag) {
                    ans.push_back({L, R});
                    flag = true;
                }
                ans.push_back(intervals[i]);
            } else if(r < L) {
                ans.push_back(intervals[i]);
            } else {
                L = min(L, l);
                R = max(R, r);
            }
        }
        if(!flag)
            ans.push_back({L, R});
        return ans;
    }
private:
    vector<vector<int>> ans;
};
Solution s1;
int main() {
    vector<vector<int>> ans, tmp{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> tmp2 = {4, 8};
    ans = s1.insert(tmp, tmp2);
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}