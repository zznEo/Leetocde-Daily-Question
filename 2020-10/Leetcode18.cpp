/*
    先排序，类比三个数的和
    选择的四元组的下标分别为 i, j, l, r
    枚举 i， j，设 l = j + 1，r = nums.size() - 1
    当 i + j + l + r > target 时，r--
    当 i + j + l + r < target 时，l++
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    vector<vector<int>>& fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end()); //
        vector<int> tmp;
        int n = nums.size();
        for(int i = 0;i < n - 3;i++) {
            if(i > 0 && nums[i] == nums[i - 1]) //如果数字和前一位的数字一样，直接判断下一个，去重
                continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) //如果从i开始后面三个数都比target大，那么后面不会产生比target小的和
                break;
            if(nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)//如果从前面选择i，后面选三个相加都比target小，直接让 i 变大，后面同理
                continue;
            for(int j = i + 1;j < n - 2;j++) {
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if(nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                int left = j + 1, right = n - 1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) { left++; }
                        left++;

                        while (left < right && nums[right] == nums[right - 1]) { right--; }
                        right--;
                    } else if(sum > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> ans;
};

Solution s1;
int main() {
    vector<int> tmp = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = s1.fourSum(tmp, 0);
    for(int i = 0;i < ans.size();i++) {
        for(int j = 0;j < ans[i].size();j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}