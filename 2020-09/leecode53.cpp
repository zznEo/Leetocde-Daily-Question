#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int MAXN = nums.size() + 7;
        vector<int> dp(MAXN, 0);
        for(int i = 0;i < nums.size();i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

Solution s1;
int main() {
    
    system("pause");
    return 0;
}