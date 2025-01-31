use std::collections::VecDeque;

impl Solution {
    pub fn magnificent_sets(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;

        let mut adj = vec![vec![]; n];
        for e in &edges {
            let (a, b) = (e[0] as usize - 1, e[1] as usize - 1);
            adj[a].push(b);
            adj[b].push(a);
        }

        let mut colors = vec![2; n];
        for u in 0..n {
            if colors[u] != 2 {
                continue;
            }
            colors[u] = 0;
            if !Solution::isBipartite(&adj, &mut colors, u) {
                return -1;
            }
        }

        let distances: Vec<usize> = (0..n).map(|u| Solution::getDistance(&adj, n, u)).collect();

        let mut seen = vec![false; n];
        (0..n).fold(0, |acc, x| acc + Solution::getConnectComponentMaxDistance(&adj, x, &distances, &mut seen)) as i32
    }

    fn isBipartite(adj: &Vec<Vec<usize>>, colors: &mut Vec<usize>, u: usize) -> bool {
        for &v in &adj[u] {
            if colors[v] == colors[u] {
                return false;
            } else if colors[v] != 2 {
                continue;
            }

            colors[v] = (colors[u] + 1) % 2;

            if !Solution::isBipartite(adj, colors, v) {
                return false;
            }
        }

        true
    }

    fn getDistance(adj: &Vec<Vec<usize>>, n: usize, src: usize) -> usize {
        let mut q = VecDeque::from([src]);

        let mut seen = vec![false; n];
        seen[src] = true;

        let mut result = 0;

        while !q.is_empty() {
            let size = q.len();
            for _ in 0..size {
                let u = q.pop_front().unwrap();
                for &v in &adj[u] {
                    if !seen[v] {
                        seen[v] = true;
                        q.push_back(v);
                    }
                }
            }
            result += 1;
        }

        result
    }

    fn getConnectComponentMaxDistance(adj: &Vec<Vec<usize>>, u: usize, distances: &Vec<usize>, seen: &mut Vec<bool>) -> usize {
        if seen[u] {
            return 0;
        }
        seen[u] = true;

        adj[u]
            .iter()
            .fold(distances[u], |max_distance, &v| max_distance.max(Solution::getConnectComponentMaxDistance(&adj, v, &distances, seen)))
    }
}
