#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return "";
        int pos = s.find_first_not_of(' ');
        if(pos < 0)
            return "";
        s = s.substr(pos);
        for(int i = s.size() - 1;i >= 0;i--) {
            if(s[i] != ' ')
                break;
            s.pop_back();
        }
        string tmp = "", ans = "";
        for(int i = s.size() - 1;i >= 0;i--){
            if(s[i] == ' ' && !tmp.empty()){
                reverse(tmp.begin(), tmp.end());
                tmp.push_back(' ');
                ans += tmp;
                tmp = "";
            } else if(s[i] != ' '){
                tmp.push_back(s[i]);
            }
        }
        if(tmp.size() != 0){
            reverse(tmp.begin(), tmp.end());
            ans += tmp;
        }
        
        return ans;
    }
};

Solution s1;
int main() {
    cout << s1.reverseWords(" ") << endl;
    system("pause");
    return 0;
}