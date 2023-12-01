class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        vector<int> desc;
        for (int i = 0; i < n; ++i) {
            while (!desc.empty() && nums[desc.back()] < nums[i]) {
                result[desc.back()] = nums[i];
                desc.pop_back();
            }
            desc.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            while (!desc.empty() && nums[desc.back()] < nums[i]) {
                result[desc.back()] = nums[i];
                desc.pop_back();
            }
            if (result[i] == -1) {
                desc.push_back(i);
            }
        }
        return result;
    }
};
