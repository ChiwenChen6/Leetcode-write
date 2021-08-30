func maxCount(m int, n int, ops [][]int) int {

	if len(ops) == 0 {
		return m * n
	}
	a := m
	b := n

	for _, v := range ops {
		if v[0] < a {
			a = v[0]
		}
		if v[1] < b {
			b = v[1]
		}
	}

    return a * b
    
}
