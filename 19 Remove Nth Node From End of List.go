/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {    
    dummy := &ListNode{Next: head}
    slow, fast := dummy, dummy
    
    for i := 0; i <= n; i++ {
        fast = fast.Next
    }
    
    for fast != nil {
        fast = fast.Next
        slow = slow.Next
    }
    
    slow.Next = slow.Next.Next
    
    return dummy.Next
}   
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 2.2 MB
