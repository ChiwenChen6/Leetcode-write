class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def subseq(w1, w2):
            i = 0
            if not (set(w1)<set(w2) or set(w1)==set(w2)):
                return False
            for c in w2:
                if i < len(w1) and w1[i] == c:
                    i += 1
            return i == len(w1)

        c = Counter(strs)
        ustrs = list(c.keys())
        ustrs.sort(key=len, reverse=True)
        for i, word in enumerate(ustrs):
            if c[word]==1 and all([not subseq(word, w) for w in ustrs[:i]]):
                return len(word)
        else:
            return -1
          
          
          
          
# 98 / 98 test cases passed.
# Status: Accepted
# Runtime: 34 ms
# Memory Usage: 14.2 MB
