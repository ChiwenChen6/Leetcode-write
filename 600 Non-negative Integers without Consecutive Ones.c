

int findIntegers(int n){
    int c = 0, i = 0;
        while (i <= n) {
            int j = i & (i >> 1);
            if (j) {
                i += j; 
            } else {
                c++; 
                i++; 
            }
        }
        return c;

}


// 1001100 i
// 0100110 i >> 1
// 0000100 i & (i >> 1)
// 1010000 -> next number in the sequence



// 527 / 527 test cases passed.
// Status: Accepted
// Runtime: 812 ms
// Memory Usage: 5.5 MB
// Submitted: 1 minute ago
