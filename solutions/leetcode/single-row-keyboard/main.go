func abs(num int) int {
	if num > 0 {
		return num
	}
	return -num
}

func calculateTime(keyboard string, word string) int {
	keyPosition := [26]int{}
	for i, k := range keyboard {
		keyPosition[k-'a'] = i
	}
	p := 0
	result := 0
	for _, c := range word {
		q := keyPosition[c-'a']
		result += abs(p - q)
		p = q
	}
	return result
}
