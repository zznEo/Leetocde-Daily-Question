#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>& permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
    }
private:
    vector<vector<int>> ans;
};

Solution s1;
int main() {
    
    system("pause");
    return 0;
}