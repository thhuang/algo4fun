use std::collections::HashMap;

impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut result = 0;
        let mut frequency = HashMap::new();

        for c in s.chars() {
            *frequency.entry(c).or_insert(0) += 1;
        }

        for v in frequency.values() {
            if *v < 3 {
                result += v;
            } else if v % 2 == 0 {
                result += 2;
            } else {
                result += 1;
            }
        }

        result
    }
}
