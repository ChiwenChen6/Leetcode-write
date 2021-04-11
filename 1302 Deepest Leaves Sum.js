/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var deepestLeavesSum = function(root) {
    let q = [root], ans, qlen, curr
    while (q.length) {
        qlen = q.length, ans = 0
        for (let i = 0; i < qlen; i++) {
            curr = q.shift(), ans += curr.val
            if (curr.left) q.push(curr.left)
            if (curr.right) q.push(curr.right)
        }
    }
    return ans
};

Runtime: 104 ms, faster than 87.40% of JavaScript online submissions for Deepest Leaves Sum.
Memory Usage: 48.6 MB, less than 78.82% of JavaScript online submissions for Deepest Leaves Sum.
