class Solution {
    fun isPowerOfThree(n: Int): Boolean 
	{
        return (n > 0 && 1162261467 % n == 0);      // 3 ^ 19 = 1162261467

	}    
}

// Status: Accepted
// Runtime: 248 ms
// Memory Usage: 35.5 MB
