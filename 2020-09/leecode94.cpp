#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int>& inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return ans;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(root->left != nullptr)
            dfs(root->left);
        ans.push_back(root->val); 
        if(root->right != nullptr)
            dfs(root->right);
    }
private:
    vector<int> ans;
};

Solution s1;
int main() {
    TreeNode *rt = new TreeNode(1);
    TreeNode *rt4 = new TreeNode(4);
    TreeNode *rt1 = new TreeNode(2);
    TreeNode *rt2 = new TreeNode(3);
    rt->left = rt4;
    rt->right = rt1;
    rt1->left = rt2;
    vector<int> ans = s1.inorderTraversal(rt);
    for(auto&i:ans)
        cout << i << endl;
    system("pause");
    return 0;
}
