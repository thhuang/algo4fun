use std::collections::VecDeque;

impl Solution {
    const DIRECTIONS: [[i32; 2]; 4] = [[1, 0], [-1, 0], [0, 1], [0, -1]];

    pub fn find_max_fish(grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        let mut seen = vec![vec![false; n]; m];
        let mut result = 0;
        for i in 0..m {
            for j in 0..n {
                result = result.max(Solution::bfs(&grid, i, j, &mut seen))
            }
        }
        result
    }

    fn bfs(grid: &Vec<Vec<i32>>, r: usize, c: usize, seen: &mut Vec<Vec<bool>>) -> i32 {
        let mut result = 0;
        let mut q = VecDeque::from([(r as i32, c as i32)]);

        while let Some((i, j)) = q.pop_front() {
            if i < 0 || grid.len() as i32 <= i || j < 0 || grid[0].len() as i32 <= j ||
                seen[i as usize][j as usize] || grid[i as usize][j as usize] == 0 {
                continue;
            }
            seen[i as usize][j as usize] = true;

            result += grid[i as usize][j as usize];
            for [di, dj] in Solution::DIRECTIONS {
                q.push_back((i + di, j + dj));
            }
        }

        result
    }
}
