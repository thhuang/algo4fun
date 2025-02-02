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

impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        nums.iter()
            .zip(nums.iter().cycle().skip(1))
            .filter(|(&a, &b)| a > b)
            .count()
            <= 1
    }
}
