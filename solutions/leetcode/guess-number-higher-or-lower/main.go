/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
	// [l, r)
	l := 1
	r := n + 1

	for r-l > 1 {
		m := l + (r-l)/2
		if guess(m) == -1 {
			r = m
		} else {
			l = m
		}
	}

	return l
}
