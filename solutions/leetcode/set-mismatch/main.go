func findErrorNums(nums []int) []int {
	nums = append(nums, 0)

	for i := 0; i < len(nums); i++ {
		for i != nums[i] && nums[i] != nums[nums[i]] {
			j := nums[i]
			nums[i], nums[j] = nums[j], nums[i]
		}
	}

	for i, v := range nums {
		if i != v {
			return []int{v, i}
		}
	}

	return nil
}
