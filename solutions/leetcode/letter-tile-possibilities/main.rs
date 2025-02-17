impl Solution {
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut char_freq: [i32; 26] = [0; 26];
        for c in tiles.chars() {
            char_freq[c as usize - b'A' as usize] += 1;
        }
        Self::process(&mut char_freq)
    }

    fn process(char_freq: &mut [i32; 26]) -> i32 {
        let mut result = 0;

        for i in 0..26 {
            if char_freq[i] == 0 {
                continue
            }

            result += 1;
            char_freq[i] -= 1;
            result += Self::process(char_freq);
            char_freq[i] += 1;
        }

        result
    }
}
