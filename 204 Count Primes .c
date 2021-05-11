int countPrimes(int n){
    if((n == 0) || (n == 1) || (n == 2)) {
        return 0;
    }
    
    bool prime_array[n+1];
    memset(prime_array, true, sizeof(prime_array));
    int i, j;
    for(i=2; i*i <= n; i++) {
        if(prime_array[i] == true) {
            for(j=(i*i); j <= n; j=j+i) {
                prime_array[j] = false;
            }
        }
    }
    int count = 0;

    for(i=2; i<n; i++) {
        if(prime_array[i] == true) {
            count++;
        }
    }
    return count;
}

// Runtime: 36 ms, faster than 55.05% of C online submissions for Count Primes.
// Memory Usage: 10.9 MB, less than 39.45% of C online submissions for Count Primes.
