func findMin(nums []int) int {
    start,end := 0,len(nums)-1
	var mid int
	for start < end{
		if nums[start] < nums[end]{
			return nums[start]
		}
		mid = (start + end) / 2
		if nums[mid] > nums[end]{
			start = mid + 1
		}else{
			end = mid
		}
	}
	return nums[start]
}
