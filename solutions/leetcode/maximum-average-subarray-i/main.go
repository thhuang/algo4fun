import "math"

func findMaxAverage(nums []int, k int) float64 {
	result := float64(math.MinInt64)
	var window float64
	for r := 0; r < len(nums); r++ {
		l := r - k + 1
		window += float64(nums[r])
		if l < 0 {
			continue
		}
		result = max(result, window/float64(k))
		window -= float64(nums[l])
	}
	return result
}
