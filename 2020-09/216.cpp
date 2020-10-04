#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>& combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
private:
    void dfs(int pos, int k, int n){
        if(k == 0 && n == 0){
            ans.push_back(tmp);
            return ;
        }
        for(int i = pos;i <= 9;i++){
            if(n >= i){
                tmp.push_back(i);
                dfs(i + 1, k-1, n - i);
                tmp.pop_back();
            } else {
                break;
            }
        }
        return ;
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
};
Solution s1;
void test() {
    vector<vector<int>> ans = s1.combinationSum3(3, 9);
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