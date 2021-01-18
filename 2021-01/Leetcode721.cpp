#include <bits/stdc++.h>
using namespace std;

class Djst{
public:
    vector<int> F, rank;
    Djst() = default;
    Djst(int n) {
        for(int i = 0;i <= n;i++)
            F.push_back(i), rank.push_back(0);
    }

    inline int Find(int x) {
        return x == F[x] ? x : F[x] = Find(F[x]);
    }

    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if(fx != fy) {
            if(rank[fx] < rank[fy]) swap(fx, fy);
            F[fy] = fx;
            if(rank[fx] == rank[fy]) rank[fx]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mail_mp;
        vector<vector<string>> ans;
        Djst ds(accounts.size());
        for(int i = 0;i < accounts.size();i++) {
            for(int j = 1;j < accounts[i].size();j++) {
                string s = accounts[i][j];
                if(mail_mp.find(s) == mail_mp.end()) {
                    mail_mp[s] = i;
                } else {
                    ds.Union(i, mail_mp[s]);
                }
            }
        }

        unordered_map<int, vector<string>> fmp;
        for(auto &it : mail_mp) {
            fmp[ds.Find(it.second)].emplace_back(it.first);
        }
        for(auto &it : fmp) {
            sort(it.second.begin(), it.second.end());
            vector<string> tmp;
            tmp.push_back(accounts[it.first][0]);
            for(int i = 0;i < it.second.size();i++) tmp.push_back(it.second[i]);
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};

Solution s1;
int main() {
    vector<vector<string>> tmp = {{"John", "johnsmith@mail.com", "john00@mail.com"},
    {"John", "johnnybravo@mail.com"},
    {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    {"Mary", "mary@mail.com"},
    };

    tmp = s1.accountsMerge(tmp);
    for(int i = 0;i < tmp.size();i++) {
        for(int j = 0;j < tmp[i].size();j++) {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}