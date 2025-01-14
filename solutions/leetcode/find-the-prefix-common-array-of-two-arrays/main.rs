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
