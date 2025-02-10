impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut chars: Vec<char> = vec![];
        for c in s.chars() {
            if !c.is_numeric() {
                chars.push(c);
            } else if !chars.is_empty() {
                chars.pop();
            }
        }
        chars.into_iter().collect()
    }
}