#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for(int i = 0;i <= N;i++) dp[1][i] = i;
        for(int i = 2;i <= K;i++) {
            int k = 2;
            dp[i][1] = 1;
            for(int j = 2;j <= N;j++) {
                if(k < j && dp[i-1][k - 1] < dp[i][j - k]) ++k;
                dp[i][j] = max(dp[i-1][k-1], dp[i][j - k]) + 1;
            }
        }
        return dp[K][N];
    }
};

Solution s1;
int main() {
    cout << s1.superEggDrop(2, 100) << endl;
    return 0;
}