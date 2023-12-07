class Solution {
    class Window {
        unordered_map<int, int> numFreq;
        int numCount = 0;

       public:
        void insert(int v) {
            if (++numFreq[v] == 1) {
                ++numCount;
            }
        }

        void remove(int v) {
            if (--numFreq[v] == 0) {
                --numCount;
            }
        }

        int size() { return numCount; }
    };

   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int result = 0;

        Window wl, wr;
        for (int r = 0, ll = 0, lr = 0; r < nums.size(); ++r) {
            wl.insert(nums[r]);
            wr.insert(nums[r]);

            while (wl.size() > k) {
                wl.remove(nums[ll++]);
            }

            while (wr.size() >= k) {
                wr.remove(nums[lr++]);
            }

            result += lr - ll;
        }

        return result;
    }
};
