func longestOnes(nums []int, k int) int {
	result := 0

	for l, r := 0, 0; r < len(nums); r++ {
		if nums[r] == 0 {
			k--
		}
		for k < 0 {
			if nums[l] == 0 {
				k++
			}
			l++
		}
		result = max(result, r-l+1)
	}

	return result
}
