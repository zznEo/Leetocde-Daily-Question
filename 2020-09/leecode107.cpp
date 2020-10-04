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
    vector<vector<int>>& levelOrderBottom(TreeNode* root) {

        if(root == nullptr)
            return ans;
        auto troot = root;
        que.push(Node{0, root});
        int last = 0;
        while(!que.empty()) {
            auto now_rt = que.front(); que.pop();
            last = max(last, now_rt.depth);
            sta.push(now_rt);
            if(now_rt.rt->left != nullptr)
                que.push({now_rt.depth + 1, now_rt.rt->left});
            if(now_rt.rt->left != nullptr)
                que.push({now_rt.depth + 1, now_rt.rt->right});
        }

        return ans;
    }
private:
    struct Node {
        int depth;
        TreeNode* rt;
    };
    queue<Node> que;
    stack<Node> sta;
    vector<vector<int>> ans;
    map<int, int> mp;
};

Solution s1;
void test() {
    TreeNode* root = new TreeNode(3);
    TreeNode* p1 = new TreeNode(9);
    TreeNode* p2 = new TreeNode(20);
    TreeNode* p3 = new TreeNode(15);
    TreeNode* p4 = new TreeNode(7);
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;
    vector<vector<int>> ans = s1.levelOrderBottom(root);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;i < ans[i].size();j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main(){
    test();
    system("pause");
    return 0;
}