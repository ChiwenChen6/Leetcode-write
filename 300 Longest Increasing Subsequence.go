
import "sort"

func lengthOfLIS(nums []int) int {
	end := make([]int, 0, len(nums))

	for _, n := range nums {
		at := sort.SearchInts(end, n)
		if at == len(end) {

			end = append(end, n)
		} else if end[at] > n {
			end[at] = n
		}
	}

	return len(end)
}
