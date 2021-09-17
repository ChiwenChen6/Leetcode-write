func intersect(nums1 []int, nums2 []int) []int {
    if len(nums1) > len(nums2) { return intersect(nums2, nums1) }
    sort.Ints(nums1)
    sort.Ints(nums2)
    res := make([]int, 0, len(nums1))
    p1 := 0
    p2 := 0
    for p1 < len(nums1) && p2 < len(nums2) {
        if nums1[p1] == nums2[p2] {
            res = append(res, nums1[p1])
            p1++
            p2++
        } else if nums1[p1] > nums2[p2] {
            p2++
        } else {
            p1++
        }
    }
    return res

}
