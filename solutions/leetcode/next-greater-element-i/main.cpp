class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (empty(nums1) || empty(nums2)) return {};

        unordered_map<int, int> next_greater;
        vector<int> st;
        for (int i = 0; i < size(nums2); ++i) {
            while (!empty(st) && st.back() < nums2[i]) {
                next_greater[st.back()] = nums2[i];
                st.pop_back();
            }
            st.push_back(nums2[i]);
        }

        vector<int> ans;
        for (int q : nums1) {
            auto it = next_greater.find(q);
            if (it == next_greater.end()) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(it->second);
        }

        return ans;
    }
};
