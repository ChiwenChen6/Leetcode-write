
###      solution 1



class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        B0 = [[i,B[i],0] for i in range(len(B))]
        A.sort()
        B0.sort(key = lambda x:x[1])
        p2 = 0
        wasted = 1
        for p1 in A:
            if p1 > B0[p2][1]:
                B0[p2][2] = p1
                p2 += 1
            else:
                B0[-wasted][2] = p1
                wasted += 1
        B0.sort(key = lambda x : x[0])
				
        return [i[2] for i in B0]
    


###        solution 2


         second = []
         for i,ele in enumerate(B):
             second.append((ele,i))
         second = sorted(second,key = lambda x:x[0],reverse = True)
         ans = [None]*len(A)
         A.sort(reverse = True)
         for ele in second:
             if A[0] > ele[0]:
                 ans[ele[1]] = A[0]
                 del A[0]
         for i in range(len(ans)):
             if ans[i] == None:
                 ans[i] = A[0]
                 del A[0]
         return ans
