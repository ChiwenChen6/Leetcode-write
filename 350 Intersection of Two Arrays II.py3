class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result=[]
        for i in nums1:
            if i in nums2:
                result.append(i)
                nums2.remove(i)
        return result
