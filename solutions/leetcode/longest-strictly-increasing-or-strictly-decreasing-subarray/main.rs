impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let mut result = 1;
        let mut increase = 1;
        let mut decrease = 1;
        for i in 1..nums.len() {
            if nums[i - 1] < nums[i] {
                increase += 1;
                decrease = 1;
            } else if nums[i - 1] > nums[i] {
                increase = 1;
                decrease += 1;
            } else {
                increase = 1;
                decrease = 1;
            }
            result = result.max(increase).max(decrease);
        }
        result
    }
}
