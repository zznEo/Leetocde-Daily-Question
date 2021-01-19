#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;

public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return true;
    }
};

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size() < 2) return 0;
        DisjointSetUnion dsu(points.size() + 1);
        for(int i = 0;i < points.size();i++) {
            for(int j = i+1;j < points.size();j++) {
                E.push_back(Edge(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])));
            }
        }
        sort(E.begin(), E.end(), [](Edge a, Edge b) -> bool {return a.cost < b.cost;});
        int ans = 0, cnt = 1;
        for(int i = 0;i < E.size();i++) {
            if(dsu.unionSet(E[i].u, E[i].v)) {
                ans += E[i].cost;
                cnt++;
                if(cnt == points.size())  break;
            }
        }
        return ans;
    }
private:
    struct Edge{
        int u, v, cost;
        Edge() = default;
        Edge(int u, int v, int cost):u(u),v(v),cost(cost){}
    };
    vector<Edge> E;
    
};

Solution s1;
int main() {
    vector<vector<int>> point = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << s1.minCostConnectPoints(point) << endl;
    return 0;
}