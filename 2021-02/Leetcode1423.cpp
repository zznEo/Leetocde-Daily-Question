#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0;
        k = n-k;
        for(int i = 0;i < k;i++)
            sum += cardPoints[i];
        int ret = 0;
        for(int i = 0;i < n;i++)
            ret += cardPoints[i];
        if(k == 0) return ret;
        int ans = ret - sum;
        for(int i = k, l = 0;i < n;i++,l++) {
            sum -= cardPoints[l];
            sum += cardPoints[i];
            ans = max(ans, ret - sum);
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {11,49,100,20,86,29,72};
    cout << s1.maxScore(tmp, 4) << endl;
    return 0;
} 