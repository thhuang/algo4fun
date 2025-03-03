impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();

        let mut result = 0;
        let mut seen = vec![vec![false; n]; m];

        for i in 0..m {
            let mut count = 0;
            for j in 0..n {
                if grid[i][j] == 1 {
                    count += 1;
                }
            }
            if count <= 1 {
                continue;
            }

            for j in 0..n {
                if grid[i][j] == 1 && !seen[i][j] {
                    seen[i][j] = true;
                    result += 1;
                }
            }
        }

        for j in 0..n {
            let mut count = 0;
            for i in 0..m {
                if grid[i][j] == 1 {
                    count += 1;
                }
            }
            if count <= 1 {
                continue;
            }

            for i in 0..m {
                if grid[i][j] == 1 && !seen[i][j] {
                    seen[i][j] = true;
                    result += 1;
                }
            }
        }

        result
    }
}

impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();

        let mut row_count = vec![0; m];
        let mut col_count = vec![0; n];

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    row_count[i] += 1;
                    col_count[j] += 1;
                }
            }
        }

        let mut result = 0;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1) {
                    result += 1;
                }
            }
        }

        result
    }
}
