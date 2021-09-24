class Solution {
    fun tribonacci(n: Int): Int {
        var n0 = 0
        var n1 = 1
        var n2 = 1
        var result = 0;
        if (n < 1) return 0
        if (n <= 2) return 1
        for(i in 3..n){
            result = n0 + n1 + n2
            n0 = n1
            n1 = n2
            n2 = result
        }
        return result;
    }
}

// Runtime: 120 ms
// Memory Usage: 32.3 MB
// Submitted: 0 minutes ago
