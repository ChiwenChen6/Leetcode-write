class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        
        if s%k != 0:
            return False
        
        used = [0]*len(nums)
        
        return self.search(0,nums,0,k,used,s//k)
    
        
    
    def search(self,start,nums,bucket,k,used,t):
        
        if k == 1:
            return True
        
        if bucket == t:
            return self.search(0,nums,0,k-1,used,t)
            
        for i in range(start,len(nums)):
            
            if used[i] != 1 and bucket + nums[i] <= t:
                used[i] = 1
                
                if self.search(i+1,nums,bucket+nums[i],k,used,t):
                    return True
                
                used[i] = 0
                
        return False
        
        
        
#         Runtime: 60 ms, faster than 63.38% of Python3 online submissions for Partition to K Equal Sum Subsets.
# Memory Usage: 14.3 MB, less than 78.07% of Python3 online submissions for Partition to K Equal Sum Subsets.
