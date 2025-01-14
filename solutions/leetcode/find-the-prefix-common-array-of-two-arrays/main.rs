impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut seen = vec![false; a.len() + 1];
        let mut acc = 0;
        let mut result = Vec::new();

        for i in 0..a.len() {
            if seen[a[i] as usize] {
                acc += 1;
            }
            seen[a[i] as usize] = true;

            if seen[b[i] as usize] {
                acc += 1;
            }
            seen[b[i] as usize] = true;

            result.push(acc);
        }

        result
    }
}

impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut a_mask: u64 = 0;
        let mut b_mask: u64 = 0;

        let mut result: Vec<i32> = Vec::new();

        for i in 0..a.len() {
            a_mask |= 1u64 << a[i];
            b_mask |= 1u64 << b[i];
            result.push((a_mask & b_mask).count_ones() as i32);
        }

        result
    }
}
