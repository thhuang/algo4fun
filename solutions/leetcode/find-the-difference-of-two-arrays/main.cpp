class Solution {
   public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> intersection;
        for (int v : s1) {
            if (s2.count(v) > 0) intersection.push_back(v);
        }
        for (int v : intersection) {
            s1.erase(v);
            s2.erase(v);
        }
        return {{s1.begin(), s1.end()}, {s2.begin(), s2.end()}};
    }
};

class Solution {
   public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> result(2);
        copy_if(s1.begin(), s1.end(), back_inserter(result[0]),
                [&s2](int v) { return s2.count(v) == 0; });
        copy_if(s2.begin(), s2.end(), back_inserter(result[1]),
                [&s1](int v) { return s1.count(v) == 0; });
        return result;
    }
};
