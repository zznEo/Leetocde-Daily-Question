#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        int i = 0;
        while(i <= blue) {
            if(nums[i] == 0) {
                swap(nums[red], nums[i]);
                i++;
                red++;
            } else if(nums[i] == 2) {
                swap(nums[blue], nums[i]);
                blue--;
            } else {
                i++;
            }
        }
    }
};

Solution s1;
int main() {
    vector<int> tmp = {2, 0, 2, 1, 1, 0};
    s1.sortColors(tmp);
    for(auto &i:tmp)
        cout << i << " ";
    cout << endl;
    system("pause");
    return 0;
}