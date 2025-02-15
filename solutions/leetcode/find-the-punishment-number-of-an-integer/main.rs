impl Solution {
    pub fn punishment_number(n: i32) -> i32 {
        (1..n + 1)
            .filter(|&i| Self::check(i * i, i))
            .fold(0, |acc, x| acc + x * x)
    }

    fn check(num: i32, target: i32) -> bool {
        if target < 0 || num < target {
            return false;
        }

        if num == target {
            return true;
        }

        Self::check(num / 10, target - num % 10)
            || Self::check(num / 100, target - num % 100)
            || Self::check(num / 1000, target - num % 1000)
    }
}
