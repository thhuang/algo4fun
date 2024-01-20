const mod = 1e9 + 7

func sumSubarrayMins(arr []int) int {
	n := len(arr)

	asc := []int{}

	r := make([]int, n)
	for i, v := range arr {
		for len(asc) > 0 && arr[asc[len(asc)-1]] > v {
			r[asc[len(asc)-1]] = i - 1
			asc = asc[:len(asc)-1]
		}
		asc = append(asc, i)
	}
	for len(asc) > 0 {
		r[asc[len(asc)-1]] = n - 1
		asc = asc[:len(asc)-1]
	}

	l := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		v := arr[i]
		for len(asc) > 0 && arr[asc[len(asc)-1]] >= v {
			l[asc[len(asc)-1]] = i + 1
			asc = asc[:len(asc)-1]
		}
		asc = append(asc, i)
	}
	for len(asc) > 0 {
		l[asc[len(asc)-1]] = 0
		asc = asc[:len(asc)-1]
	}

	result := 0
	for i, v := range arr {
		result = (result + v*(i-l[i]+1)*(r[i]-i+1)) % mod
	}

	return result
}
