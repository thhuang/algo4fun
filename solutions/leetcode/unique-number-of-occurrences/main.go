func uniqueOccurrences(arr []int) bool {
	occurrences := map[int]int{}
	for _, v := range arr {
		occurrences[v]++
	}

	occurrencesFrequency := map[int]int{}
	for _, v := range occurrences {
		occurrencesFrequency[v]++
		if occurrencesFrequency[v] > 1 {
			return false
		}
	}

	return true
}
