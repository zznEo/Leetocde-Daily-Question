#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (hash.find(val) != hash.end()) return false;
        nums.push_back(val);
        hash[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (hash.find(val) == hash.end()) return false;

        int pos = hash[val];
        nums[pos] = nums.back();
        nums.pop_back();
        hash[nums[pos]] = pos;
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int pos = rand()%nums.size();  //对下标产生随机数
        return nums[pos];
    }
private:
    unordered_map<int, int> hash;
    vector<int> nums;
};

int main() {
    RandomizedSet s;
    return 0;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */