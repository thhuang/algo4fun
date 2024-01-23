func isPalindrome(bs []byte) bool {
	for i := 0; i < len(bs)/2; i++ {
		if bs[i] != bs[len(bs)-1-i] {
			return false
		}
	}
	return true
}

func partition(s string) [][]string {
	result := [][]string{}
	curr := []string{}

	var dfs func(int)
	dfs = func(i int) {
		if i == len(s) {
			p := make([]string, len(curr))
			copy(p, curr)
			result = append(result, p)
			return
		}

		bytes := []byte{}
		for j := i; j < len(s); j++ {
			bytes = append(bytes, s[j])
			if !isPalindrome(bytes) {
				continue
			}
			curr = append(curr, string(bytes))
			dfs(j + 1)
			curr = curr[:len(curr)-1]
		}
	}

	dfs(0)

	return result
}
