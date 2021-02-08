#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() < 2) return arr.size();
        int n = arr.size();
        int l = 0, r = 0, ans = 1;
        while(r < n-1) {
            if(l == r) {
                if(arr[l] == arr[l+1])
                    l++;
                r++;
            } else {
                if(arr[r-1] < arr[r] && arr[r] > arr[r+1]) {
                    r++;
                } else if(arr[r-1] > arr[r] && arr[r+1] > arr[r]) {
                    r++;
                } else {
                    l = r;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {9,4,2,10,7,8,8,1,9};
    cout << s1.maxTurbulenceSize(tmp) << endl;
    return 0;
}