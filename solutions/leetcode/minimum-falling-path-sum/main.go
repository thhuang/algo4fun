import "math"

func minFallingPathSum(matrix [][]int) int {
	m := len(matrix)
	n := len(matrix[0])

	dp := matrix[0]
	for i := 1; i < m; i++ {
		dpNew := make([]int, n)
		for j := 0; j < n; j++ {
			v := dp[j]
			if j-1 >= 0 {
				v = min(v, dp[j-1])
			}
			if j+1 < n {
				v = min(v, dp[j+1])
			}
			dpNew[j] = matrix[i][j] + v
		}
		dp = dpNew
	}

	result := math.MaxInt32
	for _, v := range dp {
		result = min(result, v)
	}

	return result
}

import "math"

func minFallingPathSum(matrix [][]int) int {
    m := len(matrix)
    n := len(matrix[0])

    dp := matrix[0]
    for i := 1; i < m; i++ {
        dpNew := make([]int, n)
        copy(dpNew, dp)
        for j := 0; j < n; j++ {
            if j - 1 >= 0 {
                dpNew[j] = min(dpNew[j], dp[j - 1])
            }
            if j + 1 < n {
                dpNew[j] = min(dpNew[j], dp[j + 1])
            }
            dpNew[j] += matrix[i][j]
        }
        dp = dpNew
    }

    result := math.MaxInt32
    for _, v := range dp {
        result = min(result, v)
    }

    return result
}
