class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        
        if (courses == None or len(courses) == 0) :
            return 0
        
        new_sort = sorted(courses, key = lambda x:x[1])
        count = 0
        tmpsum = 0
        
        heap=[]
        # lsit 2 heap
        heapify(heap)
        for i in range(len(courses)):
            heappush(heap, -1 * new_sort[i][0])  #to create max_heap multiply by -1
            tmpsum += new_sort[i][0]
            count += 1
			
            if  tmpsum > new_sort[i][1] :
                tmpsum += heappop(heap)
                count -= 1

        return count
