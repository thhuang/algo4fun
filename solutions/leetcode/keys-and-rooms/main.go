func canVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)
	vis := make([]bool, n)

	var dfs func(int)
	dfs = func(u int) {
		if vis[u] {
			return
		}
		vis[u] = true
		for _, v := range rooms[u] {
			dfs(v)
		}
	}

	dfs(0)

	for _, b := range vis {
		if !b {
			return false
		}
	}
	return true
}
