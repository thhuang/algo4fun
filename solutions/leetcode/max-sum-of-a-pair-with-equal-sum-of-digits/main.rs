use std::collections::HashMap;

impl Solution {
    pub fn maximum_sum(nums: Vec<i32>) -> i32 {
        let mut result = -1;
        let mut map: HashMap<i32, (i32, i32)> = HashMap::new();
        for &num in nums.iter() {
            let digit_sum = Self::sum_of_digits(num);
            let (mut a, mut b) = map.entry(digit_sum).or_insert((-1, -1));
            if b >= num {
                continue;
            } else if num > a {
                (a, b) = (num, a)
            } else {
                (a, b) = (a, num);
            }
            map.insert(digit_sum, (a, b));
            if b != -1 {
                result = result.max(a + b);
            }
        }
        result
    }

    fn sum_of_digits(mut num: i32) -> i32 {
        let mut result = 0;
        while num > 0 {
            result += num % 10;
            num /= 10;
        }
        result
    }
}
