#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>& combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
private:
    void dfs(int pos, int n, int k){
        if(tmp.size() == k){
            ans.push_back(tmp);
            return ;
        }
        if(tmp.size() + (n - pos + 1) < k)
            return ;
        tmp.push_back(pos);
        dfs(pos + 1, n, k);
        tmp.pop_back();
        dfs(pos+1, n, k);
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
};
Solution s1;
void test() {
    vector<vector<int>> ans = s1.combine(2, 1);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    test();
    system("pause");
    return 0;
}