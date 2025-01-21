use std::cmp;

impl Solution {
    pub fn grid_game(grid: Vec<Vec<i32>>) -> i64 {
        let n = grid[0].len();

        let mut first_row_suffix = vec![0i64; n + 1];
        let mut second_row_suffix = vec![0i64; n + 1];

        for i in (0..n).rev() {
            first_row_suffix[i] = first_row_suffix[i + 1] + grid[0][i] as i64;
            second_row_suffix[i] = second_row_suffix[i + 1] + grid[1][i] as i64;
        }

        let mut result = first_row_suffix[1];
        for i in (1..n) {
            let first = first_row_suffix[i + 1];
            let second = second_row_suffix[0] - second_row_suffix[i];
            result = cmp::min(result, cmp::max(first, second));
        }

        return result;
    }
}
