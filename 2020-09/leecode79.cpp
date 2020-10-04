#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                if(board[i][j] == word[0]){
                    memset(vis, 0, sizeof(vis));
                    q.push(P(i, j));
                    vis[i][j] = 1;
                    if(bfs(board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }

    bool bfs (vector<vector<char>>& board, string word, int pos){
        while(!q.empty() && pos < word.size()){
            P now = q.front(); q.pop();
            P next;
            pos++;
            for(int i = 0;i < 4;i++){
                next.first = now.first + next_pos[i][0];
                next.second = now.second + next_pos[i][1];
                if(next.second < m && next.first < n && next.first >= 0 && next.second >= 0 && vis[next.first][next.second] == 0 && word[pos] == board[next.first][next.second]){
                    vis[next.first][next.second] = 1;
                    q.push(next);
                }
            }
        }
        return pos == word.size();
    }

private:
    int next_pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    int vis[201][201] = {0};
    queue<pair<int, int>> q;
    using P = pair<int, int>;
};

Solution s1;
void test() {
    vector<vector<char>> board = {{'A','B','C','E'},
                                {'S','F','E','S'},
                                {'A','D','E','E'}};
    string s = "ABCESEEEFS";
    cout << s1.exist(board, s) << endl;
}

int main(){
    test();
    system("pause");
    return 0;
}