use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut result = 0;

        let mut product_freq = HashMap::new();
        for i in 0..n {
            for j in i + 1..n {
                let k = nums[i] * nums[j];
                *product_freq.entry(k).or_insert(0) += 1;
            }
        }

        for freq in product_freq.values() {
            let pairs = freq * (freq - 1) / 2;
            result += 8 * pairs;
        }

        result as i32
    }
}
