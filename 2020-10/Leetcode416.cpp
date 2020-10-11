#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty())
            return true;
        else if(nums.size() == 1)
            return false;
        int sum = 0;
        for(int i = 0;i < nums.size();i++)  sum += nums[i];
        if(sum % 2 != 0)
            return false;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum, 0));
        for(int i = 1;i <= nums.size();i++) {
            for(int j = sum / 2;j >= 0;j--) {
                if(j >= nums[i-1])
                    dp[i][j] = max(dp[i-1][j - nums[i-1]] + nums[i-1], dp[i - 1][j]);
            }
        }
        return sum/2 == dp[nums.size()][sum/2];
    }
private:
};

Solution s1;
int main() {
    vector<int> tmp = {2, 2, 1, 1};
    cout << s1.canPartition(tmp) << endl;
    return 0;
}