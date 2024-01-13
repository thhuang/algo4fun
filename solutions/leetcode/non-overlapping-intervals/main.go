func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][1] < intervals[j][1]
	})

	result := 0
	p := math.MinInt
	for _, lr := range intervals {
		if lr[0] < p {
			result++
		} else {
			p = lr[1]
		}
	}

	return result
}
