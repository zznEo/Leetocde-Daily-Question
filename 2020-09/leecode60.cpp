#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        long long cnt = 1;
        for(int i = 1;i < n;i++)
            cnt *= i;
        long long tcnt = cnt;
        int i = 1;
        while(k > 0){
            if(k - cnt < 0)
                break;
            k -= cnt;
            i++;
        }
        string a;
        a.push_back(i+'0');
        for(int j = 1;j <= n;j++){
            if(j == i)
                continue;
            a.push_back((j+'0'));
        }
        while(--k){
            next_permutation(a.begin(), a.end());
        }
        return a;
    }
};
Solution s1;
void test() {
    cout << s1.getPermutation(3, 3) << endl;
}

int main(){
    test();
    system("pause");
    return 0;
}