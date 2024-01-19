func asteroidCollision(asteroids []int) []int {
	result := []int{}
	for _, v := range asteroids {
		if v > 0 {
			result = append(result, v)
			continue
		}

		for len(result) > 0 && 0 < result[len(result)-1] && result[len(result)-1] < -v {
			result = result[:len(result)-1]
		}

		if len(result) > 0 && result[len(result)-1] == -v {
			result = result[:len(result)-1]
		} else if len(result) == 0 || result[len(result)-1] < 0 {
			result = append(result, v)
		}
	}

	return result
}

func asteroidCollision(asteroids []int) []int {
	result := []int{}
	for _, v := range asteroids {
		if v > 0 {
			result = append(result, v)
			continue
		}

		for len(result) > 0 && 0 < result[len(result)-1] && result[len(result)-1] < -v {
			result = result[:len(result)-1]
		}

		if len(result) == 0 || result[len(result)-1] < 0 {
			result = append(result, v)
		} else if result[len(result)-1] == -v {
			result = result[:len(result)-1]
		}
	}

	return result
}
