func minSteps(s string, t string) int {
	freq := [26]int{}
	for _, c := range s {
		freq[c-'a']++
	}
	for _, c := range t {
		freq[c-'a']--
	}
	result := 0
	for _, v := range freq {
		if v > 0 {
			result += v
		}
	}
	return result
}
