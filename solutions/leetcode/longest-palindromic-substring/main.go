type substring struct {
	start int
	end   int
}

func longestPalindrome(s string) string {
	search := func(l, r int) substring {
		for 0 <= l && r < len(s) && s[l] == s[r] {
			l--
			r++
		}
		return substring{
			start: l + 1,
			end:   r - 1,
		}
	}

	result := substring{}

	for i := 0; i < len(s); i++ {
		got := search(i, i)
		if got.end-got.start > result.end-result.start {
			result = got
		}
	}

	for i := 1; i < len(s); i++ {
		got := search(i-1, i)
		if got.end-got.start > result.end-result.start {
			result = got
		}
	}

	return s[result.start : result.end+1]
}
