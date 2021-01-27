#include <bits/stdc++.h>
using namespace std;


class dsu{
public:
    dsu(int n) {
        for(int i = 0;i < n + 1;i++)
            size.push_back(0), F.push_back(i);
        cnt = n;
    }

    int Find(int x) {return x == F[x]?x : F[x] = Find(F[x]);}

    bool Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if(x == y) return false;

        if(size[x] < size[y])
            swap(x, y);
        F[y] = x;
        size[x] += size[y];
        cnt--;
        return true;
    }
public:
    vector<int> size, F;
    int cnt = 0;
};

class Solution {
public:
    Solution(){ios::sync_with_stdio(false);cin.tie(nullptr);}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu dsua(n), dsub(n);
        int ans = 0;
        for(int i = 0;i < edges.size();i++) {
            if(edges[i][0] == 3) {
                if(!dsua.Union(edges[i][1]-1, edges[i][2]-1))
                    ans++;
                dsub.Union(edges[i][1]-1, edges[i][2]-1);
            }
        }
        for(int i = 0;i < edges.size();i++) {
            if(edges[i][0] == 1) {
                if(!dsua.Union(edges[i][1]-1, edges[i][2]-1))
                    ans++;
            } else if(edges[i][0] == 2) {
                if(!dsub.Union(edges[i][1]-1, edges[i][2]-1))
                    ans++;
            }
        }
        if(dsua.cnt != 1 || dsub.cnt != 1)
            return -1;
        return ans;
    }
};

Solution s1;
int main() {
    vector<vector<int>> edge = {{3,1,2}, {3,2,3}, {1,1,3}, {1,2,4},{1,1,2},{2,3,4}};
    int n = 4;
    cout << s1.maxNumEdgesToRemove(n, edge) << endl;
    return 0;

}