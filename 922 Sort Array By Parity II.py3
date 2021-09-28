class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        odd = []
        even = []
        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                odd.append(nums[i])
            else:
                even.append(nums[i])

        k = []
        for j in range(len(odd)):
            k.append(odd[j])
            k.append(even[j])
        return k
      
      
#       61 / 61 test cases passed.
# Status: Accepted
# Runtime: 208 ms
# Memory Usage: 16.6 MB
