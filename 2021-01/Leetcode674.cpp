#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int ans = 1, max_pre = nums[0], tmp = 1;
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] > max_pre) {
                tmp++;
            } else {
                ans = max(ans, tmp);
                tmp = 1;
            }
            max_pre = nums[i];
        }
        return ans;    
    }
};

Solution s1;
int main() {
    vector<int> tmp = {1,3,5,4,7};
    cout << s1.findLengthOfLCIS(tmp) << endl;
    return 0;
}