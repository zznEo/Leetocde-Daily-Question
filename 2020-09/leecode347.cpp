#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>& topKFrequent(vector<int>& nums, int k) {
        for(auto&it: nums)
            mp[it]++;
        sort(nums.begin(), nums.end());
        for(auto &it : nums){
            Set.insert(make_pair(mp[it], it), greater<int>);
        }
        while(k--){
            auto now = *Set.begin();
            ans.push_back(now.second);
        }
    }
private:
    map<long long, int> mp;
    set<pair<int, int>> Set;
    vector<int> ans;
};


Solution s1;
void test() {
    vector<int> ans, nums = {1, 1, 1, 2, 2, 3};
    ans = s1.topKFrequent(ans, 2);
    for_each(ans.begin(), ans.end(), [](int t){cout << t << endl;});
}

int main(){
    test();
    system("pause");
    return 0;
}