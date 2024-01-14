type PQ []int

func (pq PQ) Len() int {
	return len(pq)
}

func (pq PQ) Less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PQ) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PQ) Pop() any {
	old := *pq
	n := len(old)
	v := old[n-1]
	*pq = old[:n-1]
	return v
}

func (pq *PQ) Push(v any) {
	*pq = append(*pq, v.(int))
}

type SmallestInfiniteSet struct {
	mn     int
	exists map[int]struct{}
	pq     PQ
}

func Constructor() SmallestInfiniteSet {
	return SmallestInfiniteSet{
		mn:     1,
		exists: map[int]struct{}{},
		pq:     PQ{},
	}

}

func (this *SmallestInfiniteSet) PopSmallest() int {
	if len(this.pq) == 0 {
		this.mn++
		return this.mn - 1
	}

	v := heap.Pop(&this.pq).(int)
	delete(this.exists, v)

	return v
}

func (this *SmallestInfiniteSet) AddBack(num int) {
	if num >= this.mn {
		return
	}
	if _, ok := this.exists[num]; ok {
		return
	}
	this.exists[num] = struct{}{}
	heap.Push(&this.pq, num)
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.PopSmallest();
 * obj.AddBack(num);
 */
