#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        dp.resize(n+1);
        for(int i = 2;i <= n;i++) {
            if(s[i-1] == ')') {
                if(s[i-2] == '(')
                    dp[i] = dp[i-2] + 2;
                else if(i - dp[i-1] - 2 >= 0 && s[i - dp[i-1] - 2] == '(') {
                        dp[i] =  dp[i-1] + dp[i - dp[i-1] - 2] + 2;
                    else 
                        dp[i] = dp[i-1] + 2;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
private:
    vector<int> dp;
};

Solution s1;
int main() {
    cout << s1.longestValidParentheses(")()())") << endl;
    return 0;
}