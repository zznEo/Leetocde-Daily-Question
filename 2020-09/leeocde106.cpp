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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return nullptr;
        return dfs(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
private:
    TreeNode* dfs(int lin, int rin, int lpos, int rpos, vector<int>& ino, vector<int>& post) {
        if(lin > rin)
            return nullptr;
        TreeNode *root = new TreeNode(post[rpos]);
        int rootin = lin;
        while(rootin <= rin && ino[rootin] != root->val)
            rootin++;
        int len = rootin - lin;
        root->left = dfs(lin, rootin - 1, lpos, lpos + len - 1, ino, post);
        root->right = dfs(rootin + 1, rin, lpos + len, rpos - 1, ino, post);

        return root;  
    }
public:
    void Pint(TreeNode* root) {
        if(root == nullptr)
            return ;
        cout << root->val << endl;
        Pint(root->left);
        Pint(root->right);
    }
};


Solution s1;
int main() {
    vector<int> ino = {9,3,15,20,7};
    vector<int> post = {9,15,7,20,3};
    TreeNode *root = s1.buildTree(ino, post);
    s1.Pint(root);
    system("pause");
    return 0;
}