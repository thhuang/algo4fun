impl Solution {
    const DIRECTIONS: [(i32, i32); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];

    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len() as i32;
        let n = grid[0].len() as i32;

        let mut vis = vec![vec![-1; n as usize]; m as usize];
        let mut stack = vec![(0, 0)];

        for c in 0..(m + n) {
            let mut new_vis = vec![];

            while let Some((i, j)) = stack.pop() {
                if (i < 0 || m <= i || j < 0 || n <= j || vis[i as usize][j as usize] != -1) {
                    continue;
                }
                if (i == m - 1 && j == n - 1) {
                    return c;
                }

                vis[i as usize][j as usize] = c;
                new_vis.push((i, j));

                let (di, dj) = Solution::DIRECTIONS[(grid[i as usize][j as usize] - 1) as usize];
                stack.push((i + di, j + dj));
            }

            for (i, j) in new_vis {
                for &(di, dj) in Solution::DIRECTIONS.iter() {
                    stack.push((i + di, j + dj));
                }
            }
        }

        0
    }
}
