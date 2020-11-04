#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() <= 1)
            return true;
        int pos = 0;
        while(pos < bits.size() - 1) {
            if(bits[pos] == 0)
                pos++;
            else 
                pos += 2;
        }
        if(pos == bits.size())
            return false;
        return true;
    }
};

Solution s1;
int main() {
    
    system("pause");
    return 0;
}