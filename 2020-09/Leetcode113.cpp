#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>>& pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return ans;
        vector<int> tmp;
        tmp.push_back(root->val);
        dfs(root, tmp, sum, root->val);
        return ans;
    }

    void dfs(TreeNode* root, vector<int> tmp, int sum, int tsum) {
        if(root->left == nullptr && root->right == nullptr) {
            if(sum == tsum) {
                ans.push_back(tmp);
            }
            return ;
        }

        if(root->left != nullptr) {
            tmp.push_back(root->left->val);
            dfs(root->left, tmp, sum, tsum + root->left->val);
            tmp.pop_back();
        }

        if(root->right != nullptr) {
            tmp.push_back(root->right->val);
            dfs(root->right, tmp, sum, tsum + root->right->val);
            tmp.pop_back();
        }
    }
private:
    vector<vector<int>> ans;
};

Solution s1;
int main() {
    TreeNode *r1 = new TreeNode(5);
    TreeNode *r2 = new TreeNode(4);
    TreeNode *r3 = new TreeNode(8);
    TreeNode *r4 = new TreeNode(11);
    TreeNode *r6 = new TreeNode(13);
    TreeNode *r7 = new TreeNode(4);
    TreeNode *r8 = new TreeNode(7);
    TreeNode *r9 = new TreeNode(2);
    TreeNode *r10 = new TreeNode(5);
    TreeNode *r11 = new TreeNode(1);

    r1->left = r2;
    r1->right = r3;

    r2->left = r4;
    r3->left = r6;
    r3->right = r7;
    r4->left = r8;
    r4->right = r9;
    r7->left = r10;
    r7->right = r11;

    vector<vector<int>> ans = s1.pathSum(r1, 22);

    for(int i = 0;i < ans.size();i++) {
        for(int j = 0;j < ans[i].size();j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}