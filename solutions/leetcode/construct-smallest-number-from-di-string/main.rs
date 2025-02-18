impl Solution {
    pub fn smallest_number(pattern: String) -> String {
        let mut result = String::new();
        let mut stack: Vec<i32> = Vec::new();
        for i in (0..=pattern.len()) {
            stack.push((i + 1) as i32);
            if i == pattern.len() || pattern.chars().nth(i).unwrap() == 'I' {
                while let Some(v) = stack.pop() {
                    result.push_str(&v.to_string());
                }
            }
        }
        result
    }
}
