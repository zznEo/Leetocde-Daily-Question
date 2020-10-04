#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void QuickSort(vector<int>& nums){
        dfs(0, nums.size()-1, nums);
    }

    void dfs(int low, int high, vector<int>& nums){
        if(low < high){
            int priv = nums[low];
            int i = low + 1;
            int j = low + 1;
            while(j <= high){
                if(nums[j] < priv){
                    swap(nums[i], nums[j]);
                    i++;
                }
                j++;
            }
            swap(nums[low], nums[i-1]);
            dfs(low, i - 2, nums);
            dfs(i, high, nums);
        }
    }
};

Solution s1;
void test(){
    vector<int> nums = {4,3,5,1,54,64,312,4};
    s1.QuickSort(nums);
    for(auto&x:nums)
        cout << x << " ";
    cout << endl;
}

int main(){
    test();
    system("pause");
    return 0;
}