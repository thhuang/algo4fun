impl Solution {
    pub fn remove_occurrences(s: String, part: String) -> String {
        let mut t: Vec<char> = vec![];
        for c in s.chars() {
            t.push(c);
            if t.len() >= part.len()
                && t.iter().rev().take(part.len()).collect::<String>()
                    == part.chars().rev().collect::<String>()
            {
                t.truncate(t.len() - part.len());
            }
        }
        t.iter().collect()
    }
}
