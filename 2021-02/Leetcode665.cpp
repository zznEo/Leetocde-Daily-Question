#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 0) return true;
        int cnt = 0;
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] < nums[i-1]) {
                cnt++;
                if(cnt > 1) return false;
                if(i == 1|| nums[i] >= nums[i - 2])  nums[i - 1] = nums[i];
                else {
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }   
};

Solution s1;
int main() {
    vector<int> tmp = {2,4,1,2};
    cout << s1.checkPossibility(tmp) << endl;
    for(int i = 0;i < tmp.size();i++) cout << tmp[i] << " ";
    cout << endl;
    return 0;
}