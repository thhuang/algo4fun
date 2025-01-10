impl Solution {
    pub fn word_subsets(words1: Vec<String>, words2: Vec<String>) -> Vec<String> {
        let char_frequency = |s: &String| -> [usize; 26] {
            s.as_bytes().iter().fold([0; 26], |mut acc, &c| {
                acc[(c - b'a') as usize] += 1;
                acc
            })
        };
        let target = words2
            .iter()
            .map(char_frequency)
            .fold(vec![0; 26], |acc, w| {
                acc.iter().enumerate().map(|(i, &f)| w[i].max(f)).collect()
            });
        words1
            .into_iter()
            .filter(|w| {
                char_frequency(w)
                    .iter()
                    .enumerate()
                    .all(|(i, &f)| f >= target[i])
            })
            .collect()
    }
}
