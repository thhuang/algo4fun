impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        let mut diff: Vec<usize> = vec![];
        for (i, (c1, c2)) in s1.chars().zip(s2.chars()).enumerate() {
            if c1 != c2 {
                if diff.len() == 2 {
                    return false;
                }
                diff.push(i)
            }
        }
        if diff.len() == 0 {
            true
        } else if diff.len() != 2 {
            false
        } else {
            let (i, j) = (diff[0], diff[1]);
            (s1.chars().nth(i), s1.chars().nth(j)) == (s2.chars().nth(j), s2.chars().nth(i))
        }
    }
}

impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        let diff: Vec<_> = s1
            .chars()
            .zip(s2.chars())
            .filter(|(c1, c2)| c1 != c2)
            .collect();
        match diff.len() {
            0 => true,
            2 => (diff[0].0, diff[0].1) == (diff[1].1, diff[1].0),
            _ => false,
        }
    }
}
