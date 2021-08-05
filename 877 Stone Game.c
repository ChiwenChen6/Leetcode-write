bool stoneGame(int* piles, int pilesSize){
    int a1 = 0, a2 = 0;
    int l1 = 0, l2 = 0;
    int sz = pilesSize;
    int *p = piles;
    int i = 0, j = 1;
    int l = sz - 1, m = sz - 2;
    
    while (i<sz || j<sz || l>=0 || m>=0) {
        i<sz ? a1+=p[i], i+=2 : 0;
        j<sz ? l1+=p[j], j+=2 : 0;
        l>=0 ? a2+=p[l], l-=2 : 0;
        m>=0 ? l2+=p[m], m-=2 : 0;
    }
    return a1>l1 || a2>l2;
}


// //
// 46 / 46 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 5.7 MB
// Submitted: 0 minutes ago
