impl Solution {
    pub fn minimize_xor(num1: i32, num2: i32) -> i32 {
        let mut n = num2.count_ones() as i32 - num1.count_ones() as i32;
        let mut result = num1;

        for i in 0..32 {
            let mask = 1 << i;
            if n > 0 && result & mask == 0 {
                n -= 1;
                result |= mask;
            } else if n < 0 && result & mask != 0 {
                n += 1;
                result ^= mask;
            }
        }

        result
    }
}
