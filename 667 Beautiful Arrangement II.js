/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var constructArray = function(n, k) {
    let ans = new Array(n)
    for (let i = 0, a = 1, z = k + 1; i <= k; i++)
        ans[i] = i % 2 ? z-- : a++
    for (let i = k + 1; i < n;)
        ans[i] = ++i
    return ans
};

// 04/13/2021 10:09	Accepted	92 ms	40.4 MB	javascript
