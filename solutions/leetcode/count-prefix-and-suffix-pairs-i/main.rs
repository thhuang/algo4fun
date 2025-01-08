impl Solution {
    pub fn count_prefix_suffix_pairs(words: Vec<String>) -> i32 {
        words
            .iter()
            .enumerate()
            .map(|(i, s)| {
                words[i + 1..words.len()]
                    .iter()
                    .filter(|t| t.starts_with(s) && t.ends_with(s))
                    .count() as i32
            })
            .sum::<i32>()
    }
}
