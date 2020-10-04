#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> tmp = nums;
        int l = 0, r= nums.size() - 1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] % 2 == 0)
                tmp[r--] = nums[i];
            else 
                tmp[l++] = nums[i];
        }
        return tmp;
    }
};

Solution s1;
int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> tmp = s1.exchange(nums);
    for(auto&i:tmp)
        cout << i << " ";
    system("pause");
    return 0;
}