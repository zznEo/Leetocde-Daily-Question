#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
            root = new TreeNode(val);
        else 
            dfs(root, val);
        return root;
    }
private:
    void dfs(TreeNode* root, int val) {

        if(root->val > val) {
            if(root->left != nullptr) {
                insertIntoBST(root->left, val);
            } else {
                root->left = new TreeNode(val);
                return ;
            }
        } else if(root->val < val) {
            if(root->right != nullptr) {
                insertIntoBST(root->right, val);
            } else {
                root->right = new TreeNode(val);
                return ;
            }
        }
    }
};

Solution s1;
int main() {
    TreeNode* r1 = new TreeNode(4);
    s1.insertIntoBST(r1, 2);
    
    system("pause");
    return 0;
}