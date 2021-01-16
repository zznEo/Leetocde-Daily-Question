#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        Init(s, s.size());
        for(int i = 0;i < pairs.size();i++) {
            Union(pairs[i][0], pairs[i][1]);
        }
        for(int i = 0;i < s.size();i++) {
            nums[Find(i)].push_back(i);
        }
        for(int i = 0;i < s.size();i++) {
            cout << i << " : ";
            for(int j = 0;j < nums[i].size();j++) {
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0;i < s.size();i++) {
            vector<char> tmp;
            for(int j = 0;j < nums[i].size();j++) {
                tmp.push_back(s[nums[i][j]]);
            }
            sort(tmp.begin(), tmp.end());
            for(int j = 0;j < nums[i].size();j++) s[nums[i][j]] = tmp[j];
            tmp.clear();
        }
        return s;
    }
private:
    void Init(string s, int n) {
        for(int i = 0;i <= n+1;i++) F.push_back(i), rank.push_back(0);
        for(int i = 0;i < s.size();i++) tmp.push_back(Node{s[i], i});
        nums.resize(n+1);
    }
    int Find(int x) {
        return F[x] == x?x:F[x] = Find(F[x]);
    }
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if(fx != fy) {
            if(rank[fx] < rank[fy])
                swap(fx, fy);
            F[fy] = fx;
            if(rank[fx] == rank[fy]) rank[fx] += 1;
        }
    }
private:
    vector<int> F, rank;
    struct Node {
        char ch;
        int id;
    };
    vector<Node> tmp;
    vector<vector<int>> nums;
};
Solution s1;
int main() {
    vector<vector<int>> nums = {{0,3}, {1, 2}, {0, 2}};
    string s = "dcab";
    cout << s1.smallestStringWithSwaps(s, nums) << endl;
    return 0;
}