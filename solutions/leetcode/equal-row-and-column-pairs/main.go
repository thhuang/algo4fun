import "strconv"

func equalPairs(grid [][]int) int {
	n := len(grid)

	freq := map[string]int{}
	for _, row := range grid {
		s := []string{}
		for _, v := range row {
			s = append(s, strconv.Itoa(v))
		}
		freq[strings.Join(s, ":")]++
	}

	result := 0
	for j := 0; j < n; j++ {
		s := []string{}
		for i := 0; i < n; i++ {
			s = append(s, strconv.Itoa(grid[i][j]))
		}
		result += freq[strings.Join(s, ":")]
	}

	return result
}
