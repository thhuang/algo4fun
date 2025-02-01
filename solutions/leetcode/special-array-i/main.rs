impl Solution {
    pub fn is_array_special(nums: Vec<i32>) -> bool {
        (1..nums.len()).fold(true, |acc, i| acc && nums[i - 1] % 2 + nums[i] % 2 == 1)
    }
}
