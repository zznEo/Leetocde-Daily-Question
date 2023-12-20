#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for(int i = 0;i < nums.size();i++) {
            if (len < 2 || nums[len - 2] != nums[i]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
}s;

int main() {
    vector<int> tmp = {1,1,1,2,2,3};
    cout << s.removeDuplicates(tmp) << endl;
    return 0;
}