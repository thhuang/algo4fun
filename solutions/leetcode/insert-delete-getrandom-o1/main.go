import "math/rand"

type RandomizedSet struct {
	Vals       []int
	ValToIndex map[int]int
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		Vals:       []int{},
		ValToIndex: map[int]int{},
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.ValToIndex[val]; ok {
		return false
	}

	this.ValToIndex[val] = len(this.Vals)
	this.Vals = append(this.Vals, val)

	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.ValToIndex[val]; !ok {
		return false
	}

	valIndex := this.ValToIndex[val]
	lastVal := this.Vals[len(this.Vals)-1]

	this.ValToIndex[lastVal] = valIndex
	this.Vals[valIndex] = lastVal

	this.Vals = this.Vals[:len(this.Vals)-1]
	delete(this.ValToIndex, val)

	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.Vals[rand.Intn(len(this.Vals))]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
