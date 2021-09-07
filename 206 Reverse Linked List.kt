/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun reverseList(head: ListNode?): ListNode? {
        var current = head
        var prev: ListNode? = null
        while (current != null) {
            val temp = current.next
            current.next = prev
            prev = current
            current = temp
        }
    return prev
    }
}
// Runtime: 152 ms, faster than 95.13% of Kotlin online submissions for Reverse Linked List.
// Memory Usage: 36.2 MB, less than 27.49% of Kotlin online submissions for Reverse Linked List.
