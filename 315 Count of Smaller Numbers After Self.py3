class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        arr=[]
        count=[0]*len(nums)
        for i in range(len(nums)-1,-1,-1):
            index=bisect.bisect_left(arr,nums[i])
            # 陣列二分演算法 (Array bisection algorithm)
            count[i]=index
            arr.insert(index,nums[i])
        return count
