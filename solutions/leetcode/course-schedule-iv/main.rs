impl Solution {
    pub fn check_if_prerequisite(
        num_courses: i32,
        prerequisites: Vec<Vec<i32>>,
        queries: Vec<Vec<i32>>,
    ) -> Vec<bool> {
        let n = num_courses as usize;

        let mut is_prerequisite = vec![vec![false; n]; n];

        for p in &prerequisites {
            is_prerequisite[p[0] as usize][p[1] as usize] = true;
        }

        for u in 0..n {
            for s in 0..n {
                for t in 0..n {
                    is_prerequisite[s][t] =
                        is_prerequisite[s][t] || is_prerequisite[s][u] && is_prerequisite[u][t];
                }
            }
        }

        let mut result = Vec::with_capacity(queries.len());
        for q in queries.iter() {
            result.push(is_prerequisite[q[0] as usize][q[1] as usize])
        }

        result
    }
}
