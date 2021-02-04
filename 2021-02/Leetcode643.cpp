#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = k;
        int sum = 0;
        for(int i = 0;i < k;i++)
            sum += nums[i];
        double ans = sum*1.0 / k;
        while(r < nums.size()) {
            sum -= nums[l];
            sum += nums[r];
            l++, r++;
            ans = max(ans, sum*1.0/k);
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {1,12,-5,-6,50,3};
    cout << s1.findMaxAverage(tmp, 4) << endl;
    return 0;
}