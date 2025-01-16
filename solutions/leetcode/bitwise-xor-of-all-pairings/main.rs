impl Solution {
    pub fn xor_all_nums(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut result = 0;
        if nums2.len() % 2 == 1 {
            for &v in nums1.iter() {
                result ^= v;
            }
        }
        if nums1.len() % 2 == 1 {
            for &v in nums2.iter() {
                result ^= v;
            }
        }
        result
    }
}
