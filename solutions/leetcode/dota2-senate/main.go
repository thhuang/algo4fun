func predictPartyVictory(senate string) string {
	radiant := 0
	dire := 0
	q := []rune{}
	for _, c := range senate {
		if c == 'R' {
			radiant++
		} else { // c == 'D'
			dire++
		}
		q = append(q, c)
	}

	r := 0
	d := 0
	for radiant > 0 && dire > 0 {
		c := q[0]
		q = q[1:]
		if c == 'R' {
			if r < 0 {
				r++
				radiant--
			} else {
				d--
				q = append(q, c)
			}
		} else { // c == 'D'
			if d < 0 {
				d++
				dire--
			} else {
				r--
				q = append(q, c)
			}
		}
	}

	if radiant > 0 {
		return "Radiant"
	}
	return "Dire"
}
