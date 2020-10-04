#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(int n) {
        if(n <= 1)
            return 1;
        
        int ans1 = 1,ans2 = 1;
        for(int i = 2;i <= n;i++) {
            int tmp = (ans1 + ans2) % mod;
            ans1 = ans2 % mod;
            ans2 = tmp % mod;
        }
        return ans2;
    }
};

Solution s1;
int main() {
    cout << s1.numWays(7) << endl;
    system("pause");
    return 0;
}