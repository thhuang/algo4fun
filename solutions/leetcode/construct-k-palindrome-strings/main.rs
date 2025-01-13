impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        s.len() >= k as usize
            && s.bytes()
                .fold(0u32, |acc, b| acc ^ 1 << (b - b'a'))
                .count_ones()
                <= k as u32
    }
}
