#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string>& commonChars(vector<string>& A) {
        for(int j = 0;j < 26;j++){
                min_cnt[j] = INT_MAX;
            }
        for(int i = 0;i < A.size();i++) {
            memset(cnt, 0, sizeof(cnt));
            for(int j = 0;j < A[i].size();j++) {
                cnt[A[i][j] - 'a']++;
            }
            for(int j = 0;j < 26;j++){
                min_cnt[j] = min(min_cnt[j], cnt[j]);
            }
        }

        for(int i = 0;i < 26;i++) {
            for(int j = 0;j < min_cnt[i];j++) {
                ans.push_back(string(1, i+'a'));
            }
        }
        return ans;
    }
private:
    int cnt[26] = {0};
    int min_cnt[26] = {0};
    vector<string> ans;
};

Solution s1;
int main() {
    vector<string> ans,A = {"bella","label","roller"};
    ans = s1.commonChars(A);
    for(auto &i:ans)
        cout << i << endl;
    return 0;
}