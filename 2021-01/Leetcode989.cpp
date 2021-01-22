#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> tmp;
        for(int i = A.size()-1;i >= 0;i--) {
            int sum = A[i] + K % 10;
            K /= 10;
            if(sum > 9) {
                K++;
                sum %= 10;
            }
            tmp.push_back(sum);
        }
        while(K) {
            tmp.push_back(K % 10);
            K /= 10;
        }
        return tmp;
    }
};

Solution s1;
int main() {
    vector<int> tmp = {0};
    tmp = s1.addToArrayForm(tmp, 0);
    for(auto &it :tmp) 
        cout << it << " ";
    return 0;
}