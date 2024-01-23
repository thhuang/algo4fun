func longestPalindrome(s string) int {
	freq := map[rune]int{}
	for _, r := range s {
		freq[r]++
	}

	result := 0
	for _, v := range freq {
		result += v / 2 * 2
	}

	for _, v := range freq {
		if v%2 == 1 {
			result++
			return result
		}
	}
	return result
}
