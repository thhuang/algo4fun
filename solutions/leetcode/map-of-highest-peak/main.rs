use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [(i32, i32); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];

    pub fn highest_peak(is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = is_water.len();
        let n = is_water[0].len();

        let mut result = vec![vec![-1; n]; m];

        let mut q: VecDeque<(i32, i32, i32)> = VecDeque::new();

        for i in 0..m {
            for j in 0..n {
                if is_water[i][j] == 1 {
                    q.push_back((i as i32, j as i32, 0));
                }
            }
        }

        while let Some((i, j, h)) = q.pop_front() {
            if result[i as usize][j as usize] >= 0 {
                continue;
            }
            result[i as usize][j as usize] = h;

            for (di, dj) in Solution::DIRECTIONS {
                let (ii, jj) = (i + di, j + dj);
                if 0 <= ii && ii < m as i32 && 0 <= jj && jj < n as i32 {
                    q.push_back((ii, jj, h + 1));
                }
            }
        }

        return result;
    }
}
