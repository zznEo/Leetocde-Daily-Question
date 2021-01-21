#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> F;
    vector<int> rank;
    int n;
    
public:
    UnionFind() = default;
    UnionFind(int n) {
        for(int i = 0;i <= n;i++) F.push_back(i), rank.push_back(0);
    }
    
    int Find(int x) {
        return F[x] == x ? x : F[x] = Find(F[x]);
    }
    
    bool unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x == y) 
            return false;
        if (rank[x] < rank[y]) 
            swap(x, y);
        F[y] = x;
        rank[x] += rank[y];
        return true;
    }
};


class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0;i < edges.size();i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(),[](vector<int> a, vector<int> b) ->bool{return a[2] < b[2];});
        UnionFind dsu(n+1);
        int val = 0, cnt = 0;
        for(int i = 0;i < edges.size();i++) {
            int x = edges[i][0], y = edges[i][1], cost = edges[i][2];
            if(dsu.unite(x, y)) {
                val += cost;
                cnt++;
            }
            if(cnt == n-1) 
                break;
        }
        vector<vector<int>> ans(2);
        for(int i = 0;i < edges.size();i++) {
            UnionFind tmp_dsu(n);
            int tcnt = 0, tval = 0;
            for(int j = 0;j < edges.size();j++) {
                if(i == j) continue;
                int x = edges[j][0], y = edges[j][1], cost = edges[j][2];
                if(tmp_dsu.unite(x, y)) {
                    tcnt++;
                    tval += cost;
                }
                if(tcnt == cnt)
                    break;
            }
            if(tcnt != cnt || (tcnt == cnt && tval > val)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }
            
            tmp_dsu = UnionFind(n);
            tmp_dsu.unite(edges[i][0], edges[i][1]);
            tval = edges[i][2], tcnt = 1;
            for(int j = 0;j < edges.size();j++) {
                int x = edges[j][0], y = edges[j][1], cost = edges[j][2];
                if(i == j) continue;
                if(tmp_dsu.unite(x, y)) {
                    tval += cost;
                    tcnt++;
                }
                if(tcnt == cnt)
                    break;
            }
            if(tcnt == cnt && tval == val) 
                ans[1].push_back(edges[i][3]);
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    edges = s1.findCriticalAndPseudoCriticalEdges(5, edges);
    for(int i = 0;i < edges.size();i++) {
        for(int j = 0;j < edges[i].size();j++)
            cout << edges[i][j] << " ";
        cout << endl;
    }
    return 0;
}