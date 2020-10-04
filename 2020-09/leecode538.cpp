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
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr)
            return root;
        if(root->right != nullptr)
            convertBST(root->right);
        sum += root->val;
        root->val = sum;
        if(root->left != nullptr)
            convertBST(root->left);
        return root;
    }
private:
    int sum = 0;
};

Solution s1;
int main() {
    TreeNode *r1 = new TreeNode(5);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(13);
    r1->left = r2;
    r1->right = r3;
    s1.convertBST(r1);
    system("pause");
    return 0;
}