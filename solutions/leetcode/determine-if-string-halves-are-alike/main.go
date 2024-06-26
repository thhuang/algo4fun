func halvesAreAlike(s string) bool {
	vowels := map[rune]struct{}{
		'a': struct{}{}, 'e': struct{}{}, 'i': struct{}{}, 'o': struct{}{}, 'u': struct{}{},
		'A': struct{}{}, 'E': struct{}{}, 'I': struct{}{}, 'O': struct{}{}, 'U': struct{}{},
	}
	vowelCount := 0
	for i, c := range s {
		if _, ok := vowels[c]; !ok {
			continue
		}
		if i < len(s)/2 {
			vowelCount++
		} else {
			vowelCount--
		}
	}
	return vowelCount == 0
}

func halvesAreAlike(s string) bool {
	vowelCount := 0
	for i, r := range s {
		switch r {
		case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
			if i < len(s)/2 {
				vowelCount++
			} else {
				vowelCount--
			}
		}
	}
	return vowelCount == 0
}
