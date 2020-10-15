#include <bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        bfs(root);
        return root;
    }
private:
    void bfs(Node* root) {
        que.push(root);
        int cnt = 1, tcnt = 1;
        while(!que.empty()) {
            auto now = que.front();que.pop();
            if(que.empty() || cnt == 1){
                now->next = nullptr;
                cnt = 1 << tcnt;
                tcnt++;
            } else {
                now->next = que.front();
                cnt--;
            }
            que.push(now->left);
            que.push(now->right);
        }
    }
private:
    queue<Node*> que;
};

Solution s1;
int main() {
    Node* r1 = new Node(1);
    Node* r2 = new Node(2);
    Node* r3 = new Node(3);
    Node* r4 = new Node(4);
    Node* r5 = new Node(5);
    Node* r6 = new Node(6);
    Node* r7 = new Node(7);
    r1->left = r2;
    r1->right = r3;
    r2->left = r4;
    r2->right = r5;
    r3->left = r6;
    r3->right = r7;

    Node* tmp = s1.connect(r1);
    while(tmp != nullptr){
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
    return 0;
}