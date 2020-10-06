#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        Init(N, edges);
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
private:
    void Init(int N, vector<vector<int>>& edges) {
        grep.resize(N, {});
        ans.resize(N, 0);
        dp.resize(N, 0);
        sz.resize(N, 0);
        for(auto &it:edges) {
            grep[it[0]].push_back(it[1]);
            grep[it[1]].push_back(it[0]);
        }
    }

    void dfs1(int now, int fa) {
        dp[now] = 0;
        sz[now] = 1;
          for(int i = 0;i < grep[now].size();i++) {
            if(now == grep[now][i] || grep[now][i] == fa) continue;
            dfs1(grep[now][i], now);
            dp[now] += dp[grep[now][i]] + sz[grep[now][i]];
            sz[now] += sz[grep[now][i]];
        }
    }

    void dfs2(int u, int fa) {
        ans[u] = dp[u];

        for(int i = 0;i < grep[u].size();i++) {
            int v = grep[u][i];
            if(v == u || v == fa) continue;
            int pu = dp[u], tz = sz[u];
            int tv = dp[v], ts = sz[v];
            dp[u] = dp[u] - dp[v] - sz[v];
            sz[u] = sz[u] - sz[v];
            dp[v] = dp[v] + dp[u] + sz[u];
            sz[v] = sz[v] + sz[u];
            dfs2(v, u);
            dp[u] = pu; sz[u] = tz;
            dp[v] = tv; sz[v] = ts;
        }
    }
private:
    vector<int> ans, dp, sz;
    vector<vector<int>> grep;
};

Solution s1;
int main() {
    vector<vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    vector<int> ans = s1.sumOfDistancesInTree(6, edges);
    for(auto &it:ans)
        cout << it << " ";
    cout << endl;
    system("pause");
    return 0;
}