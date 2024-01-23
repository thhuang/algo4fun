func maxLength(arr []string) int {
	candidates := [][26]bool{}
	for _, s := range arr {
		invalid := false
		chars := [26]bool{}
		for _, r := range s {
			i := r - 'a'
			if chars[i] {
				invalid = true
				break
			}
			chars[i] = true
		}
		if invalid {
			continue
		}
		candidates = append(candidates, chars)
	}

	result := 0
	vis := [26]bool{}
	var dfs func(int)
	dfs = func(i int) {
		if i == len(candidates) {
			curr := 0
			for _, b := range vis {
				if b {
					curr++
				}
			}
			result = max(result, curr)
			return
		}

		dfs(i + 1)

		for i, b := range candidates[i] {
			if b && vis[i] {
				return
			}
		}
		for i, b := range candidates[i] {
			vis[i] = vis[i] || b
		}
		dfs(i + 1)
		for i, b := range candidates[i] {
			vis[i] = vis[i] != b
		}
	}

	dfs(0)

	return result
}
