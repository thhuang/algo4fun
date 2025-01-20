use std::collections::BinaryHeap;
use std::cmp;
use std::cmp::Reverse;

impl Solution {
    const DIRECTIONS: [(i32, i32); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    pub fn trap_rain_water(height_map: Vec<Vec<i32>>) -> i32 {
        let m = height_map.len();
        let n = height_map[0].len();

        let mut min_heap = BinaryHeap::new();

        for i in 0..m {
            min_heap.push(Reverse((height_map[i][0], i, 0)));
            min_heap.push(Reverse((height_map[i][n - 1], i , n - 1)));
        }

        for j in 0..n {
            min_heap.push(Reverse((height_map[0][j], 0, j)));
            min_heap.push(Reverse((height_map[m - 1][j], m - 1, j)));
        }

        let mut vis = vec![vec![false; n]; m];
        let mut result: i32 = 0;

        while let Some(Reverse((h, i, j))) = min_heap.pop() {
            if vis[i][j] {
                continue;
            }
            vis[i][j] = true;

            result += h - height_map[i][j];

            for &(di, dj) in Solution::DIRECTIONS.iter() {
                let (ii, jj) = (i as i32 + di, j as i32 + dj);
                if 0 <= ii && ii < m as i32 && 0 <= jj && jj < n as i32 {
                    let (ii, jj) = (ii as usize, jj as usize);
                    min_heap.push(Reverse((cmp::max(h, height_map[ii][jj]), ii, jj)));
                }
            }
        }

        result
    }
}
