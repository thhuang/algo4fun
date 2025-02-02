impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        nums.iter()
            .enumerate()
            .map(|(i, &a)| a <= nums[(i + 1) % nums.len()])
            .filter(|&b| !b)
            .count()
            <= 1
    }
}
