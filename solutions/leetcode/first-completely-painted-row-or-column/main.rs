impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();

        let mut map = vec![(0, 0); m * n + 1];
        for i in 0..m {
            for j in 0..n {
                map[mat[i][j] as usize] = (i, j);
            }
        }

        let mut rows = vec![n; m];
        let mut cols = vec![m; n];

        for (i, &k) in arr.iter().enumerate() {
            let (ii, jj) = map[k as usize];
            rows[ii] -= 1;
            cols[jj] -= 1;
            if rows[ii] == 0 || cols[jj] == 0 {
                return i as i32;
            }
        }

        -1
    }
}
