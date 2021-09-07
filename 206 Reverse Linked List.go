/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var prev *ListNode
    current := head
    for current != nil {
        next := current.Next
        current.Next = prev
        prev = current
        current = next
    }
    return prev
}


// Runtime: 0 ms, faster than 100.00% of Go online submissions for Reverse Linked List.
// Memory Usage: 2.6 MB, less than 100.00% of Go online submissions for Reverse Linked List.
