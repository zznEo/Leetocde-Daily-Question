#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        const int mk = k;
        if(k >= n / 2) {
            return maxProfitK_INF(prices);
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(mk + 1, vector<int>(2, 0)));
        //0,代表没有股票，1代表有股票
        // base case：
        //     dp[-1][k][0] = dp[i][0][0] = 0
        //     dp[-1][k][1] = dp[i][0][1] = INT_MIN

        // 状态转移方程：
        //     dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
        //     dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
        // dp[0][mk][0] = 0;
        // dp[0][0][0] = 0;
        // dp[0][0][1] = INT_MIN;
        // dp[0][mk][1] = INT_MIN;
        for(int i = 0;i <= n;i++)
            dp[i][0][1] = INT_MIN;
        for(int i = 0;i <= mk;i++)
            dp[0][i][1] = INT_MIN;
        for(int i = 1;i <= n;i++) { 
            for(int k = 1;k <= mk;k++) {
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
            }
        }
        return dp[n][mk][0];
    }

    int maxProfitK_INF(vector<int>& prices) {
        int ans = 0;
        for(int i = 1;i < prices.size();i++) {
            ans +=  max(0, prices[i] - prices[i-1]);
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {3,2,6,5,0,3};
    cout << s1.maxProfit(2, tmp) << endl;
    system("pause");
    return 0;
}