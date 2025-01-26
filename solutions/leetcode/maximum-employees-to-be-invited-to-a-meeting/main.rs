use std::cmp;

impl Solution {
    pub fn maximum_invitations(favorite: Vec<i32>) -> i32 {
        let n = favorite.len();

        let mut in_degree = vec![0; n];
        for i in 0..n {
            in_degree[favorite[i] as usize] += 1;
        }

        let mut stack: Vec<usize> = vec![];
        for u in 0..n {
            if in_degree[u] == 0 {
                stack.push(u);
            }
        }

        let mut depth = vec![1; n];
        while let Some(u) = stack.pop() {
            let v = favorite[u] as usize;
            depth[v] = depth[v].max(depth[u] + 1);
            in_degree[v] -= 1;
            if in_degree[v] == 0 {
                stack.push(v);
            }
        }

        let mut max_cycle = 0;
        let mut chain = 0;

        for u in 0..n {
            if in_degree[u] == 0 {
                continue;
            }

            let mut cycle = 0;
            let mut p = u;
            while in_degree[p] != 0 {
                in_degree[p] = 0;
                cycle += 1;
                p = favorite[p] as usize;
            }

            if cycle == 2 {
                chain += depth[u] + depth[favorite[u] as usize];
            } else {
                max_cycle = max_cycle.max(cycle);
            }
        }

        cmp::max(max_cycle, chain)
    }
}
