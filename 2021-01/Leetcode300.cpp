class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, pos = 0;
        vector<int> dp(n+1);
        for(int i = 1;i <= n;i++)
            dp[i] = INT_MAX;
        dp[0] = nums[0];
        for(int i = 1;i < n;i++) {
            if(nums[i] > dp[ans]) dp[++ans] = nums[i];
            else {
                pos = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[pos] = nums[i];
                ans = max(ans, pos);
            }
        }
        return ans + 1;
    }
};