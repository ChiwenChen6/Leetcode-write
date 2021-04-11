func deepestLeavesSum(root *TreeNode) int {
    _, x := get(root, 0, 0, 0)
    return x
}

func get(root *TreeNode, level, highestLevel, sum int) (int, int) {
    if  root.Left != nil {
        highestLevel, sum = get(root.Left, level+1, highestLevel, sum)
    }
    
    if root.Right != nil {
        highestLevel, sum = get(root.Right, level+1, highestLevel, sum)
    }
    
    if root.Left == nil && root.Right == nil {
        if level > highestLevel {
            highestLevel = level
            sum = root.Val
        } else if level == highestLevel {
            sum += root.Val
        }
    }
    
    return highestLevel, sum
}

// Runtime: 28 ms, faster than 81.72% of Go online submissions for Deepest Leaves Sum.
// Memory Usage: 7.3 MB, less than 40.86% of Go online submissions for Deepest Leaves Sum.
