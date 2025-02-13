use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut min_heap: BinaryHeap<Reverse<i64>> = nums.into_iter().map(|v| Reverse(v as i64)).collect();
        let mut result = 0;
        while min_heap.len() > 1 {
            let Reverse(a) = min_heap.pop().unwrap();
            if a >= k as i64 {
                break;
            }
            let Reverse(b) = min_heap.pop().unwrap();
            min_heap.push(Reverse(a * 2 + b));
            result += 1;
        }
        result
    }
}
