import numpy
class Solution:

	def __init__(self, nums: List[int]):
		self.nums = numpy.array(nums)
		self.arr = nums

	def reset(self) -> List[int]:
		"""
		Resets the array to its original configuration and return it.
		"""
		return self.arr

	def shuffle(self) -> List[int]:
		"""
		Returns a random shuffling of the array.
		"""
		numpy.random.shuffle(self.nums)
		return self.nums
  
  
#   Runtime: 372 ms, faster than 17.57% of Python3 online submissions for Shuffle an Array.
# Memory Usage: 36.6 MB, less than 5.33% of Python3 online submissions for Shuffle an Array.
