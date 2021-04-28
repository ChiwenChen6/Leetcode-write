/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    if (n === 1) 
        return true
    if ( n < 1) 
        return false
    return isPowerOfThree(n/3)
};

// 04/28/2021 14:17	Accepted	236 ms	49.1 MB	javascript
