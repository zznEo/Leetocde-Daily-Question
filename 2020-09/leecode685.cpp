#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution(){
        for(int i = 0;i <= 1000;i++){
            f.push_back(i);
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        for(int i = 0;i < edges.size();i++){
            int x = edges[i][0], y = edges[i][1];
            int fx = Find(x), fy = Find(y);
            if(fx == fy) {
                ans.push_back(x);
                ans.push_back(y);
                break;
            } else {
                f[fy] = fx;
            }
        }
        return ans;
    }
private:
    int Find(int x){
        if(f[x] == x)
            return x;
        else
            return f[x] = Find(f[x]);
    }
private:
    vector<int> f;
    vector<int> ans;
};
 
Solution s1;
int main() {
    vector<vector<int>> edges = {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
    vector<int> ans = s1.findRedundantDirectedConnection(edges);
    cout << ans[0] << " " << ans[1] << endl;
    system("pause");
    return 0;
}