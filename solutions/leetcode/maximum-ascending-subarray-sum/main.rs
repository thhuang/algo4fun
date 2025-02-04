impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let mut result = *nums.first().unwrap();
        let mut window = *nums.first().unwrap();
        for (&a, &b) in nums.iter().zip(nums.iter().skip(1)) {
            if a < b {
                window += b;
            } else {
                window = b;
            }
            result = result.max(window);
        }
        result
    }
}
