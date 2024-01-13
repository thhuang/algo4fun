func minSteps(s string, t string) int {
	freq := [26]int{}
	for i := range s {
		freq[s[i]-'a']++
		freq[t[i]-'a']--
	}
	result := 0
	for _, v := range freq {
		result += max(0, v)
	}
	return result
}
