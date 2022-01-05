
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        d = defaultdict(list)

        for center in range(len(s)):
            for l, u in [(center, center), (center, center+1)]:
                while l >= 0 and u < len(s) and s[l] == s[u]:
                    d[l].append(u+1)
                    l -= 1
                    u += 1

        path = []

        def dfs(u):
            if u == len(s):
                yield path[:]
            else:
                for v in d[u]:
                    path.append(s[u:v])
                    yield from dfs(v)
                    path.pop()

        return dfs(0)
