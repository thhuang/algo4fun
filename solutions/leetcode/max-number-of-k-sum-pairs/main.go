func maxOperations(nums []int, k int) int {
	result := 0

	numFreq := map[int]int{}
	for _, v := range nums {
		w := k - v
		if numFreq[w] > 0 {
			result++
			numFreq[w]--
		} else {
			numFreq[v]++
		}
	}

	return result
}
