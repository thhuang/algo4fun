#[derive(Clone, Copy, PartialEq)]
enum State {
    Unknown,
    Unsafe,
    Safe,
}

impl Solution {
    fn dfs(u: usize, graph: &Vec<Vec<i32>>, states: &mut Vec<State>) -> State {
        if states[u] != State::Unknown {
            return states[u];
        }
        states[u] = State::Unsafe;

        let mut is_safe = true;

        for v in &graph[u] {
            if Solution::dfs(*v as usize, graph, states) == State::Unsafe {
                is_safe = false;
            }
        }

        if is_safe {
            states[u] = State::Safe;
        }

        states[u]
    }

    pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
        let n = graph.len();
        let mut states = vec![State::Unknown; n];
        let mut result: Vec<i32> = Vec::new();

        for u in 0..n {
            if Solution::dfs(u, &graph, &mut states) == State::Safe {
                result.push(u as i32);
            }
        }

        result
    }
}

impl Solution {
    fn dfs(u: usize, graph: &Vec<Vec<i32>>, states: &mut Vec<State>) -> State {
        if states[u] != State::Unknown {
            return states[u];
        }
        states[u] = State::Unsafe;

        let is_safe = graph[u].iter().fold(true, |acc, &v| {
            Solution::dfs(v as usize, graph, states) == State::Safe && acc
        });

        if is_safe {
            states[u] = State::Safe;
        }

        states[u]
    }

    pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
        let n = graph.len();
        let mut states = vec![State::Unknown; n];
        let mut result: Vec<i32> = Vec::new();

        for u in 0..n {
            if Solution::dfs(u, &graph, &mut states) == State::Safe {
                result.push(u as i32);
            }
        }

        result
    }
}
