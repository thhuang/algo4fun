func longestSubarray(nums []int) int {
	result := 0
	deleted := 0
	l := 0
	for r, v := range nums {
		if v == 0 {
			deleted++
		}
		for deleted > 1 {
			if nums[l] == 0 {
				deleted--
			}
			l++
		}
		result = max(result, r-l)
	}
	return result
}
