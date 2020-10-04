#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int ans = 0;
        int minn = prices[0];
        for(int i = 1;i < prices.size();i++){
            if(prices[i] > minn) {
                ans = max(ans, prices[i] - minn);
            }
            minn = min(minn, prices[i]);
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {7, 1, 5, 3, 6, 4};
    cout << s1.maxProfit(tmp) << endl;
    system("pause");
    return 0;
}