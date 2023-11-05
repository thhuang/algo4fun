class Solution {
   public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        deque<int> nums(arr.begin(), arr.end());

        int winner = numeric_limits<int>::min();
        int cnt = 0;
        while (cnt < k && cnt < n) {
            if (nums[0] < nums[1]) {
                nums.push_back(nums.front());
                nums.pop_front();
                winner = nums.front();
                cnt = 1;
            } else {
                winner = nums.front();
                nums.pop_front();
                nums.push_back(nums.front());
                nums.pop_front();
                nums.push_front(winner);
                ++cnt;
            }
        }

        return winner;
    }
};

class Solution {
   public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int cnt = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (winner > arr[i]) {
                ++cnt;
            } else {
                winner = arr[i];
                cnt = 1;
            }
            if (cnt == k) break;
        }
        return winner;
    }
};
