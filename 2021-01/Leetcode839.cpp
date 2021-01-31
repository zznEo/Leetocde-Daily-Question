#include <bits/stdc++.h>
using namespace std;


class DSU{
public:
    vector<int> F, rank;
    int cnt;
    DSU(int n) {
        for(int i = 0;i < n+1;i++)
            F.push_back(i), rank.push_back(0);
        cnt = n;
    }

    int Find(int x) {return x == F[x]? x : F[x] = Find(F[x]);}

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if(x ==y) return ;
        if(rank[x] < rank[y])
            swap(x, y);
        rank[x] += rank[y];
        F[y] = x;
        cnt--;
    }
};

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
public:
    int numSimilarGroups(vector<string>& strs) {
        DSU dsu(strs.size());
        int cnt = 0;
        for(int i = 0;i < strs.size();i++) {
            for(int j = i+1;j < strs.size();j++) {
                string str1 = strs[i];
                string str2 = strs[j];
                if(Check(str1, str2)) {
                    dsu.Union(i, j);
                }
            }
        }
        for(int i = 0;i < strs.size();i++) {
            if(dsu.F[i] == i)
                cnt++;
        }
        return cnt;
    }

private:
        bool Check(const string &a, const string &b) {
        int num = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                num++;
                if (num > 2) {
                    return false;
                }
            }
        }
        return true;
    }
};

Solution s1;
int main() {
    vector<string> strs = {"abc", "abc"};
    cout << s1.numSimilarGroups(strs) << endl;
    return 0;
}