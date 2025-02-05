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
