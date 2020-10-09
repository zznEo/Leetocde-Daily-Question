#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        const int mk = 2;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(mk + 1, vector<int>(2, 0)));
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
};
Solution s1;
int main() {
    vector<int> tmp = {7,1,5,3,6,4};
    cout << s1.maxProfit(tmp) << endl;
    system("pause");
    return 0;
}