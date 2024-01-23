import "unicode"

func isPalindrome(s string) bool {
	l := 0
	r := len(s) - 1
	for l < r {
		if !unicode.IsLetter(rune(s[l])) && !unicode.IsDigit(rune(s[l])) {
			l++
		} else if !unicode.IsLetter(rune(s[r])) && !unicode.IsDigit(rune(s[r])) {
			r--
		} else if unicode.ToLower(rune(s[l])) != unicode.ToLower(rune(s[r])) {
			return false
		} else {
			l++
			r--
		}
	}
	return true
}
