use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn lexicographically_smallest_array(nums: Vec<i32>, limit: i32) -> Vec<i32> {
        let n = nums.len();

        let mut sorted_nums = nums.clone();
        sorted_nums.sort();

        let mut group_nums: Vec<VecDeque<i32>> = vec![VecDeque::from([sorted_nums[0]])];
        let mut num_to_group: HashMap<i32, usize> = HashMap::from([(sorted_nums[0], 0)]);

        for i in 1..n {
            let num = sorted_nums[i];
            if group_nums.last().unwrap().back().unwrap() + limit < num {
                group_nums.push(VecDeque::new());
            }
            group_nums.last_mut().unwrap().push_back(num);
            num_to_group.insert(num, group_nums.len() - 1);
        }

        let mut result = Vec::with_capacity(n);
        for num in &nums {
            let group = num_to_group[&num];
            result.push(group_nums[group].pop_front().unwrap());
        }

        result
    }
}
