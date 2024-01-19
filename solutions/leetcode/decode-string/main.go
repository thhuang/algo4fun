import "unicode"

func decodeString(s string) string {
	_, rs := decodeRunes([]rune(s), 0)
	return string(rs)
}

func decodeRunes(rs []rune, i int) (int, []rune) {
	result := []rune{}

	for i < len(rs) && rs[i] != ']' {
		if unicode.IsLetter(rs[i]) {
			result = append(result, rs[i])
			i++
			continue
		}

		// is digit

		cnt := 0
		for rs[i] != '[' {
			cnt = cnt*10 + int(rs[i]-'0')
			i++
		}

		var res []rune
		i, res = decodeRunes(rs, i+1)
		for k := 0; k < cnt; k++ {
			result = append(result, res...)
		}
	}

	return i + 1, result
}


import "unicode"

func decodeString(s string) string {
    var decode func(int) (int, []rune)
    decode = func(i int) (int, []rune) {
        result := []rune{}

        for i < len(s) && s[i] != ']' {
            if unicode.IsLetter(rune(s[i])) {
                result = append(result, rune(s[i]))
                i++
                continue
            }

            k := 0
            for unicode.IsDigit(rune(s[i])) {
                k = k*10 + int(s[i]-'0')
                i++
            }
            var rs []rune
            i, rs = decode(i+1)
            for k > 0 {
                result = append(result, rs...)
                k--
            }
        }

        return i+1, result
    }

    _, rs := decode(0)
    return string(rs)
}
