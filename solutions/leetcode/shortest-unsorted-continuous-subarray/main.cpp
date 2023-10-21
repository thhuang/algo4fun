class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int small = numeric_limits<int>::max();
        int large = numeric_limits<int>::min();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] <= nums[i + 1]) continue;
            for (int j = i + 1; j < n; ++j) small = min(small, nums[j]);
            break;
        }
        for (int i = n - 1; i >= 1; --i) {
            if (nums[i - 1] <= nums[i]) continue;
            for (int j = i - 1; j >= 0; --j) large = max(large, nums[j]);
            break;
        }
        if (small > large) return 0;

        int l, r;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > small) {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < large) {
                r = i;
                break;
            }
        }

        return r - l + 1;
    }
};

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int small = numeric_limits<int>::max();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] <= nums[i + 1]) continue;
            small = *min_element(nums.begin() + i + 1, nums.end());
            break;
        }
        
        int large = numeric_limits<int>::min();
        for (int i = n - 1; i >= 1; --i) {
            if (nums[i - 1] <= nums[i]) continue;
            large = *max_element(nums.begin(), nums.begin() + i);
            break;
        }

        if (small > large) return 0;
        
        int l = find_if(nums.begin(), nums.end(), [&](int x) -> bool { return x > small; }) - nums.begin();
        int r = find_if(nums.rbegin(), nums.rend(), [&](int x) -> bool { return x < large; }) - nums.rbegin();
        
        return n - l - r;
    }
};

class Solution {
    struct NumIndex {
        int num, index;
    };

   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<NumIndex> numIndex;

        int l = n, r = 0;
        for (int i = 0, unsortedMax = numeric_limits<int>::min(); i < n; ++i) {
            while (!numIndex.empty() && numIndex.back().num > nums[i]) {
                unsortedMax = max(unsortedMax, numIndex.back().num);
                l = min(l, numIndex.back().index);
                numIndex.pop_back();
            }
            if (nums[i] < unsortedMax) r = i;
            numIndex.push_back({nums[i], i});
        }

        return max(0, r - l + 1);
    }
};
