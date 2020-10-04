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
    vector<string>& binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return ans;
        string tmp = "";
        dfs(root, tmp);
        return ans;
    }
private:
    void dfs(TreeNode* root, string tmp){
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(tmp + to_string(root->val));
            return ;
        }
        
        if(root->left != nullptr)
            dfs(root->left, tmp + to_string(root->val) + "->");
        if(root->right != nullptr)
            dfs(root->right, tmp + to_string(root->val) + "->");
    }
private:
    vector<string> ans;
};

Solution s1;
void test(){
    TreeNode* r1 = new TreeNode(1);
    TreeNode* r2 = new TreeNode(2);
    TreeNode* r3 = new TreeNode(3);
    TreeNode* r4 = new TreeNode(5);
    r1->left = r2;
    r1->right = r3;
    r2->right = r4;
    vector<string> ans = s1.binaryTreePaths(r1);
    for(auto&s:ans)
        cout << s << endl;
}

int main(){
    test();
    system("pause");
    return 0;
}