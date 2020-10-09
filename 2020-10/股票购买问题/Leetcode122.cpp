#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int ans = 0;
        for(int i = 1;i < prices.size();i++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {7,1,5,3,6,4};
    cout << s1.maxProfit(tmp) << endl;
    system("pause");
    return 0;
}