#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    for(int k = 0;k < 4;k++) {
                        int tx = i + dit[k][0];
                        int ty = j + dit[k][1];
                        if (tx < 0 || tx >= grid.size() || ty < 0 || ty >= grid[i].size() || !grid[tx][ty]) {
                            cnt++;
                        }
                    }
                    ans += cnt;
                }
            }
        }
        return ans;
    }
private:
    int ans = 0;
    int dit[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};

Solution s1;
int main() {
    vector<vector<int>> grid{{1,1}};
    cout << s1.islandPerimeter(grid) << endl;
    return 0;
}