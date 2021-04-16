

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
    
}

// Status: Accepted
// Runtime: 8 ms
// Memory Usage: 5.7 MB
