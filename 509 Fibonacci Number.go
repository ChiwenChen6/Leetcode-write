func fib(n int) int {
    
    if n <= 1 {
        return n
    }
    
    arr := make([]int, n+1)
    arr[0] = 0
    arr[1] = 1
    
    for i := 2; i <= n; i++ {
        arr[i] = arr[i-1] + arr[i-2]
    }
    
    return arr[n]
}

// 04/16/2021 11:26	Accepted	0 ms	1.9 MB	golang
