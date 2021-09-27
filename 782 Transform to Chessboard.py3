        N = len(board)
        R = [sum([board[i][j]<<j for j in range(N)]) for i in range(N) ]
        C = [sum([board[i][j]<<i for i in range(N)]) for j in range(N) ]
        def calcMove(R, N):
            def sumOne(n) :
                k = 0
                while n:
                    n = n&(n-1)
                    k+=1
                return k
            d = {}
            for i in range(N):
                if not R[i] in d:
                    d[R[i]] = []
                d[R[i]].append(i)
            akey =[]
            for k in d:
                akey.append(k)
            
            if len(akey)==2 and akey[0]^akey[1] == (1<<N) -1 and abs(sumOne(akey[0])-sumOne(akey[1]))<=1:
                a0, a1 = d[akey[0]], d[akey[1]]
                if abs(len(a0)-len(a1))>1:
                    return -1
                if len(a0) >= len(a1):
                    res = sum( [i%2  for i in a0])
                else:
                    res = sum( [i%2  for i in a1])
                return res if N%2 else min(res, max(N//2-res, 0))
            return -1
        r, c = calcMove(R, N), calcMove(C, N)
        return -1 if r == -1 or c == -1 else r + c
