
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for s in strs:
            mold = "".join(sorted(s))
            if mold not in dic:
                dic[mold] = [s]
            else:
                dic[mold] += [s]
        return dic.values()
      
      
      
#       Runtime: 96 ms, faster than 79.42% of Python3 online submissions for Group Anagrams.
# Memory Usage: 17.6 MB, less than 57.51% of Python3 online submissions for Group Anagrams.
