#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (mp.count(num)) return {mp[num], i};
            mp[target - num] = i;
        }
        return {-1, -1};
    }
};
