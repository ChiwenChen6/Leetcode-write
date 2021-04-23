    def leastBricks(self, wall: List[List[int]]) -> int:
        #call counter 
        counter: Counter[int] = collections.Counter()
            
        for row in wall:
            width: int = 0
            for brick in row[:-1]:
                width += brick
                counter[width] += 1
                
        return len(wall) - max(counter.values(), default=0)
