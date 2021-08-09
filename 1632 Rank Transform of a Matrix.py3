class DSU():
    def __init__(self):
        self.parent = {}
        self.size = {}
        
    def add(self, x):
        self.parent[x] = x
        self.size[x] = 1
        
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def unite(self, x, y):
        x, y = self.find(x), self.find(y)
        if self.size[y] < self.size[x]: y, x = x, y
        self.size[y] += self.size[x]
        self.parent[x] = y

    def get_groups(self):
        groups = defaultdict(list)
        for x in self.parent:
            groups[self.find(x)].append(x)
        return groups
    
class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        n, m = len(matrix), len(matrix[0])
        rank = [0]*(n+m)
        d = defaultdict(list)
        
        for i in range(n):
            for j in range(m):
                d[matrix[i][j]].append((i, j))
        
        for x in sorted(d):
            dsu = DSU() # create a new structure
        
            for i, j in d[x]:
                j += n 
                dsu.add(i) 
                dsu.add(j)

            for i, j in d[x]:
                j += n 
                dsu.unite(i, j)
            
            for group in dsu.get_groups().values():
                max_rank = 0
                for location in group: max_rank = max(max_rank, rank[location])
                for location in group: rank[location] = max_rank + 1
                
            for i, j in d[x]: matrix[i][j] = rank[i]
            
        return matrix
