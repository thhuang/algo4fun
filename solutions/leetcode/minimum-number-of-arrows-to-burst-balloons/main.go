import (
	"sort"
	"math"
)

func findMinArrowShots(points [][]int) int {
	sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1] })

	result := 0

	x := math.MinInt64
	for _, p := range points {
		if p[0] > x {
			x = p[1]
			result++
		}
	}

	return result
}
