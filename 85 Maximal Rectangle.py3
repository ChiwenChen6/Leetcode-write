class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m=len(matrix)
        if m==0:
            return 0
        n=len(matrix[0])
        heights=[0]*n
        heights.append(0)#to spit out the stack in the end
        ans=0
        for k in range(m):
            for j in range(n):
                if matrix[k][j]=='1':
                    heights[j]=heights[j]+1  
                else :
                    heights[j]=0
            i=0
            stack=[]
            while i<=n:
                if len(stack)==0 or heights[stack[-1]]<=heights[i]:
                    stack.append(i)
                    i+=1
                else:
                    top=stack.pop()
                    if len(stack)!=0:
                        area=heights[top]*(i-1-stack[-1])
                    else:
                        area=heights[top]*(i-1+1)
                    ans=max(area,ans)
        return ans
