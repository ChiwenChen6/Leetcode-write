class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1: return [0]

        graph = [[] for x in range(n)]
        degree = [0] * n

        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
            degree[e[0]] += 1
            degree[e[1]] += 1

        # from leaf node
        leaves = [i for i in range(n) if degree[i] == 1]

        nodes = n
        while nodes > 2:
            newleaves = []
            for i in leaves:
                degree[i] = 0
                nodes -= 1
                for j in graph[i]:
                    degree[j] -= 1
                    if degree[j] == 1:
                        newleaves.append(j)
            leaves = newleaves
        return leaves
