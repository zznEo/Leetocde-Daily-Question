#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
            return ;
        int pos = 0;
        bool flag = false;
        for(int i = nums.size()-1;i > 0;i--){
            if(nums[i] > nums[i-1]) {
                pos = i;
                flag = true;
                break;
            }
        }

        if(!flag) {
            reverse(nums.begin(), nums.end());
            return ;
        }
        int pos2 = nums.size()-1;
        for(int i = nums.size()-1;i >= pos;i--) {
            if(nums[i] > nums[pos-1]) {
                pos2 = i;
                break;
            }
        }
        swap(nums[pos-1], nums[pos2]);
        reverse(min(nums.begin() + pos, nums.end()), nums.end());
    }
};

Solution s1;
int main() {
    vector<int> nums = {2, 3, 1};
    s1.nextPermutation(nums);
    for(int i = 0;i < nums.size();i++)
        cout << nums[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}