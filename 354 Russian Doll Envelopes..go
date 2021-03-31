
func maxEnvelopes(envelopes [][]int) int {
    a := envelopes
    
    sort.Slice(a, func (i int, j int) bool {
        if a[i][0] < a[j][0] {
            return true
        } else if a[i][0] > a[j][0] {
            return false
        } else {
            return a[i][1] > a[j][1]
        }
    })
    
    dp := make([]int, len(a))    
    counter := 0

    for i := 0; i < len(a); i++  {        
        pos := sort.SearchInts(dp[:counter], a[i][1]) 
        dp[pos] = a[i][1]
        
        if pos == counter {
            counter++
        }                
    }
    
    return counter
} 



// 84 / 84 test cases passed.
// Status: Accepted
// Runtime: 20 ms
// Memory Usage: 6.2 MB
