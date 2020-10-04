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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
    TreeNode* dfs(int lpre, int rpre, int lin, int rin, vector<int>& pre, vector<int>& ino) {
        if(lpre > rpre)
            return nullptr;
        TreeNode *root = new TreeNode(pre[lpre]);
        int pos = lin;
        while(pos <= rin && ino[pos] != root->val)
            pos++;
        int len = pos - lin;
        root->left = dfs(lpre + 1, lpre + len, lin, pos - 1, pre, ino);
        root->right = dfs(lpre + len + 1, rpre, pos + 1, rin, pre, ino);

        return root;
    }
public:
    void Pint(TreeNode* root) {
        if(root == nullptr)
            return ;
        Pint(root->left); 
        Pint(root->right);
        cout << root->val << endl;
        
    }
};

Solution s1;
int main() {
    vector<int> ino = {9,3,15,20,7};
    vector<int> post = {3,9,20,15,7};
    TreeNode *root = s1.buildTree(post, ino);
    s1.Pint(root);
    system("pause");
    return 0;
}