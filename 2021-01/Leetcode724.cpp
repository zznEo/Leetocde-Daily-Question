#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
    int pivotIndex(vector<int>& nums) {
        vector<int> front, back;
        front.push_back(nums[0]);
        back.push_back(nums[nums.size()-1]);
        for(int i = 1,j = nums.size() - 2;i < nums.size();i++,j--) {
            front.push_back(front[i-1] + nums[i]);
            back.push_back(back[i-1] + nums[j]);
        }
        for(int i = 1;i < nums.size()-1;i++) {
            int l = front[i-1];
            int r = back[(nums.size() - i)];
            if(l == r) return i;
        }
        return -1;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {1, 7, 3, 6, 5, 6};
    cout << s1.pivotIndex(tmp) << endl;
    return 0;
}