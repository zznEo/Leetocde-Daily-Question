#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> suf(nums.size(), 1);
        for(int i = 0;i < nums.size();i++) {
            pre[i] = nums[i] * (i == 0 ? 1 : pre[i - 1]);
        }
        for(int i = nums.size() - 1;i >= 0;i--) {
            suf[i] = nums[i] * (i == nums.size() - 1 ? 1 : suf[i + 1]);
        }
        vector<int> ans(nums.size(), 1);
        for(int i = 0;i < nums.size();i++) {
            ans[i] = (i == 0 ? 1 : pre[i - 1]) * (i == nums.size() - 1 ? 1 : suf[i + 1]);
        }
    }
}s;

int main() {
    
    return 0;
}