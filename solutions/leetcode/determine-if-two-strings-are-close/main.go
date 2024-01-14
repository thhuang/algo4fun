func closeStrings(word1 string, word2 string) bool {
	if len(word1) != len(word2) {
		return false
	}

	charFreq1 := map[byte]int{}
	charFreq2 := map[byte]int{}
	for i := range word1 {
		charFreq1[word1[i]]++
		charFreq2[word2[i]]++
	}

	if len(charFreq1) != len(charFreq2) {
		return false
	}

	for c := range charFreq1 {
		if _, ok := charFreq2[c]; !ok {
			return false
		}
	}

	freqCount1 := map[int]int{}
	freqCount2 := map[int]int{}
	for c := range charFreq1 {
		freqCount1[charFreq1[c]]++
		freqCount2[charFreq2[c]]++
	}

	for f, c := range freqCount1 {
		if freqCount2[f] != c {
			return false
		}
	}

	return true
}
