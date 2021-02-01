#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = 0, sum2 = 0;  
        vector<int> ans;
        unordered_map<int, int> vis;
        for(int i = 0;i < A.size();i++)
            sum1 += A[i],vis[A[i]] = 1;
        for(int i = 0;i < B.size();i++)
            sum2 += B[i];
        int mid = (sum1 - sum2) >> 1;
        for(int i = 0;i < B.size();i++) {
            int x = B[i] + mid;
            if(x >= 0 && vis[x] == 1) {
                ans.push_back(x);
                ans.push_back(B[i]);
                return ans;
            }
        }
        return ans;
        return __fairCandySwap(A, B);
    }
    vector<int> __fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = accumulate(A.begin(), A.end(), 0);
        int sum2 = accumulate(B.begin(), B.end(), 0);
        int mid = (sum1 - sum2) >> 1;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()) {
            int cut = A[i] - B[j];
            if(cut == mid) {
                return {A[i], B[j]};
            } else if(cut > mid) {
                j++;
            } else {
                i++;
            }
        }
        return {};
    }
};

Solution s1;
int main() {
    vector<int> tmp1 = { 2};
    vector<int> tmp2 = {1, 3};
    tmp1= s1.fairCandySwap(tmp1, tmp2);
    cout << tmp1[0] << " " << tmp1[1] << endl;
    return 0;
}