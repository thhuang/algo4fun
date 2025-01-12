use std::cmp;

impl Solution {
    pub fn can_be_valid(s: String, locked: String) -> bool {
        if s.len() % 2 == 1 {
            return false;
        }

        let mut max_open: i32 = 0;
        let mut min_open: i32 = 0;
        let locked_chars: Vec<char> = locked.chars().collect();

        for (i, c) in s.chars().enumerate() {
            if locked_chars[i] == '0' {
                max_open += 1;
                min_open = cmp::max(0, min_open - 1);
            } else if c == '(' {
                max_open += 1;
                min_open += 1
            } else {
                max_open -= 1;
                min_open = cmp::max(0, min_open - 1);
                if min_open > max_open {
                    return false;
                }
            }
        }

        min_open == 0
    }
}
