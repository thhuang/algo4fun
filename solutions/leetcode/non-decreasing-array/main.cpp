class Solution {
   public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;
        deque<int> q = {numeric_limits<int>::min(), numeric_limits<int>::min()};
        for (int i = 0; i < nums.size(); ++i) {
            if (q.back() <= nums[i]) {
                q.push_back(nums[i]);
                q.pop_front();
                continue;
            }

            if (modified) return false;
            modified = true;

            int p0 = *q.rbegin();
            int p1 = *next(q.rbegin());
            if (p1 > nums[i]) {
                q.push_back(p0);
            } else {
                q.back() = p1;
                q.push_back(nums[i]);
            }
            q.pop_front();
        }
        return true;
    }
};

class Solution {
   public:
    bool checkPossibility(vector<int>& nums) {
        int modified = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] <= nums[i]) continue;

            if (modified) return false;
            modified = true;

            if (i == 1) {
                nums[i - 1] = nums[i];
            } else if (nums[i - 2] <= nums[i]) {
                nums[i - 1] = nums[i - 2];
            } else {
                nums[i] = nums[i - 1];
            }
        }
        return true;
    }
};
