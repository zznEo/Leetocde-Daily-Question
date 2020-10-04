#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != i){
                return i;
            }
        }
        return nums[nums.size()-1]+1;
    }
};
Solution s1;
int main() {
    
    system("pause");
    return 0;
}