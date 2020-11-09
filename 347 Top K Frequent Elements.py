
"""
Created on Mon Nov. 09 15:39 2020
Old version and rewrite here
@author: Chiwen Chen
"""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
      if List:
        freq = Counter(nums)
        key = sorted(freq.keys(), key=lambda x : freq[x] , reverse=True)
        return key[:k]
    	
'''
Runtime: 92 ms, faster than 93.14% of Python3 online submissions for Top K Frequent Elements.
Memory Usage: 18.4 MB, less than 22.09% of Python3 online submissions for Top K Frequent Elements.
'''