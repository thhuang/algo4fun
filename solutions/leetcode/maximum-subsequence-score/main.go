import "sort"
import "container/heap"

type Heap []int

func (h Heap) Len() int           { return len(h) }
func (h Heap) Less(i, j int) bool { return h[i] < h[j] }
func (h Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *Heap) Push(v any)        { *h = append(*h, v.(int)) }
func (h *Heap) Pop() any {
	old := *h
	v := old[len(old)-1]
	*h = old[:len(old)-1]
	return v
}

func maxScore(nums1 []int, nums2 []int, k int) int64 {
	n := len(nums1)

	idx := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return nums2[idx[i]] > nums2[idx[j]] })

	result := int64(0)
	window := 0
	h := &Heap{}
	heap.Init(h)

	for r := 0; r < n; r++ {
		l := r - k + 1

		window += nums1[idx[r]]
		heap.Push(h, nums1[idx[r]])

		if l < 0 {
			continue
		}

		result = max(result, int64(nums2[idx[r]])*int64(window))

		window -= heap.Pop(h).(int)
	}

	return result
}
