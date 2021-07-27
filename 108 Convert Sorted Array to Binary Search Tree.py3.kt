/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun sortedArrayToBST(nums: IntArray): TreeNode? {
        if (nums.size == 0) {
            return null
        }
        if (nums.size == 1) {
            return TreeNode(nums[0])
        }
        return TreeNode(nums[nums.size/2]).apply {
            left  = sortedArrayToBST(nums.sliceArray(0..nums.size/2-1))
            right = sortedArrayToBST(nums.sliceArray(nums.size/2+1..nums.size-1))
        }
    }
}
