func findCircleNum(isConnected [][]int) int {
	n := len(isConnected)

	rank := make([]int, n)
	group := make([]int, n)
	for i := 0; i < n; i++ {
		group[i] = i
	}

	var find func(int) int
	find = func(u int) int {
		if group[u] == u {
			return u
		}
		group[u] = find(group[u])
		return group[u]
	}

	unite := func(a, b int) {
		ga := find(a)
		gb := find(b)
		if ga == gb {
			return
		}

		if rank[ga] < rank[gb] {
			group[ga] = gb
		} else if rank[gb] < rank[ga] {
			group[gb] = ga
		} else { // equal
			group[gb] = ga
			rank[ga]++
		}
	}

	for i, row := range isConnected {
		for j, v := range row {
			if v == 1 {
				unite(i, j)
			}
		}
	}

	numGroups := map[int]struct{}{}
	for i := 0; i < n; i++ {
		numGroups[find(i)] = struct{}{}
	}

	return len(numGroups)
}
