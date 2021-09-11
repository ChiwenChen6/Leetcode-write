
def check(num,n):
    d={}
    for i in range(n):
        d[i]={}
    total=0
    for i in range(1,n):
        for j in range(i):
            curr=num[i]-num[j]
            if curr in d[j]:
                total+=d[j][curr]
                if curr in d[i]:
                    d[i][curr]+=d[j][curr]+1
                else:
                    d[i][curr]=d[j][curr]+1

            elif curr in d[i]:
                d[i][curr]+=1
            else:
                d[i][curr]=1
    return total



class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        return check(nums,len(nums))
