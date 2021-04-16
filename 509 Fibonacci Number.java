class Solution {
    public int fib(int n) {
        if (n < 2) {
            return n;
        }
        int a = 0; 
        int b = 1; 
        int temp;
        
        for (int i = 1; i < n; i++) {
            temp = a;
            a = b;
            b += temp;
        }
        return b;
    }
}

// 04/16/2021 11:28	Accepted	0 ms	35.4 MB	java
