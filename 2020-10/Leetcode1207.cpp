#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        for(auto &i:arr) {
            vis[i+1000]++;
        }
        for(int i = 0;i <= 2000;i++) {
            vis2[vis[i]]++;
        }
        for(int i = 1;i <= 1000;i++) {
            if(vis2[i] >= 2)
                return false;
        }
        return true;
    }
private:
    int vis[2001];
    int vis2[2001];
};

Solution s1;
int main() {
    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    cout << s1.uniqueOccurrences(arr) << endl;
    return 0;
}