import "sort"

func findWinners(matches [][]int) [][]int {
	players := map[int]struct{}{}
	loseFreq := map[int]int{}
	for _, match := range matches {
		winner := match[0]
		loser := match[1]
		players[winner] = struct{}{}
		players[loser] = struct{}{}
		loseFreq[loser]++
	}

	result := [][]int{[]int{}, []int{}}
	for p := range players {
		if loseFreq[p] == 0 {
			result[0] = append(result[0], p)
		} else if loseFreq[p] == 1 {
			result[1] = append(result[1], p)
		}
	}

	sort.Ints(result[0])
	sort.Ints(result[1])

	return result
}
