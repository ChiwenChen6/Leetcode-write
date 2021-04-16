/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if (n < 2) {
        return n
    }
    let a = 0, b = 1
    for (let i = 1; i < n; i++) {
        [a,b] = [b,a+b]
    }
    return b
};


// 04/16/2021 11:27	Accepted	76 ms	38.7 MB	javascript
