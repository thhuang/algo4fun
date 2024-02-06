func groupAnagrams(strs []string) [][]string {
	group := map[string][]string{}
	for _, s := range strs {
		r := []rune(s)
		sort.Slice(r, func(i, j int) bool {
			return r[i] < r[j]
		})
		t := string(r)
		if group[t] == nil {
			group[t] = []string{}
		}
		group[t] = append(group[t], s)
	}

	result := [][]string{}
	for _, g := range group {
		result = append(result, g)
	}

	return result
}
