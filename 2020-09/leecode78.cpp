#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }

    void dfs(int row, vector<int>& nums){
        ans.push_back(tmp);
        if(row == nums.size()){
            return ;
        }
        for(int i = row;i < nums.size();i++){
            tmp.push_back(nums[i]);
            dfs(i+1, nums);
            tmp.pop_back();
        }
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
};

Solution s1;
void test(){
    vector<int> tmp = {1, 2, 3};
    vector<vector<int>> ans = s1.subsets(tmp);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    test();
    system("pause");
    return 0;
}