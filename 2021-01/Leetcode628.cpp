#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max(nums[nums.size()-1]*nums[nums.size() - 2]*nums[nums.size() - 3], nums[0]*nums[1]*nums[nums.size()-1]);
    }
};

#if 0
class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int x: nums) {
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }

            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
#endif

Solution s1;
int main() {

    return 0;
}