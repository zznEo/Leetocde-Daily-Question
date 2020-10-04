#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < grid[i].size();j++) {
                if(i == 0) {
                    if(j == 0)
                        dp[i][j] = grid[0][0];
                    else
                        dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if(j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};


Solution s1;
int main() {
    vector<vector<int>> tmp = {{1,3,1},{1,5,1},{4,2,1}};
    cout << s1.maxValue(tmp) << endl;
    system("pause");
    return 0;
}