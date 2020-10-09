#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(int i = 1;i <= n;i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1] - fee);
        }
        return dp[n][0];
    }
};

Solution s1;
int main() {
    vector<int> tmp = {1,3,2,8,4,9};
    cout << s1.maxProfit(tmp, 2) << endl;
    system("pause");
    return 0;
}