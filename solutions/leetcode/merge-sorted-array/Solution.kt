class Solution {
    fun merge(nums1: IntArray, m: Int, nums2: IntArray, n: Int): Unit {
        var i = m - 1
        var j = n - 1
        for ( in m + n - 1 downTo 0) {
            when {
                i < 0 -> nums1[p] = nums2[j--]
                j < 0 -> break
                nums1[i] > nums2[j] -> nums1[p] = nums1[i--]
                else -> nums1[p] = nums2[j--]
            }
        }
    }
}