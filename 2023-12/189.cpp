#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        auto reverse = [&](int start, int end) {
            while (start < end) {
                swap(nums[start++], nums[end--]);
            }
        };
        reverse(0, nums.size() - 1);
        reverse(0, k - 1);
        reverse(k, nums.size() - 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,-100,3,99};
    s.rotate(nums, 2);
    return 0;
}