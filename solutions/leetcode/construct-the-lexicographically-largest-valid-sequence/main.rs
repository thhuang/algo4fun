impl Solution {
    pub fn construct_distanced_sequence(n: i32) -> Vec<i32> {
        let mut result: Vec<i32> = vec![0; (n * 2 - 1) as usize];
        let mut used: Vec<bool> = vec![false; (n + 1) as usize];

        Self::process(0, &mut result, &mut used, n);

        result
    }

    fn process(i: usize, result: &mut Vec<i32>, used: &mut Vec<bool>, n: i32) -> bool {
        if i == result.len() {
            return true;
        } else if result[i] != 0 {
            return Self::process(i + 1, result, used, n);
        }

        for v in (1..=n).rev() {
            if used[v as usize] {
                continue;
            }

            used[v as usize] = true;
            result[i] = v;

            if v == 1 {
                if Self::process(i + 1, result, used, n) {
                    return true;
                }
            } else if (i + v as usize) < result.len() && result[i + v as usize] == 0 {
                result[i + v as usize] = v;
                if Self::process(i + 1, result, used, n) {
                    return true;
                }
                result[i + v as usize] = 0;
            }

            result[i] = 0;
            used[v as usize] = false;
        }

        false
    }
}
