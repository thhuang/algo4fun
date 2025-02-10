use std::collections::HashMap;

impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let n = nums.len() as i64;
        let mut map: HashMap<i32, i64> = HashMap::new();
        for (i, v) in nums.iter().enumerate() {
            *map.entry(v - i as i32).or_insert(0) += 1;
        }
        map.values().fold(0, |acc, x| acc + x * (n - x)) / 2
    }
}
