func constructArray(n int, k int) []int {
	result := make([]int, 0, n)
	left, right := 1, n
	for ; left < n-k; left++ {
		result = append(result, left)
	}
	for i := 0; i <= k; i++ {
		if i%2 == 0 {
			result, left = append(result, left), left+1
		} else {
			result, right = append(result, right), right-1
		}
	}

	return result
}


// 04/13/2021 10:14	Accepted	0 ms	3.6 MB	golang
