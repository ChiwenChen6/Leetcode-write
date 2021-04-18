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
    fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {        
        var fast = head
        var step = 1
        while(step < n) {
            step++;
            fast = fast?.next
        }
        
        if(fast?.next == null) {
            return head?.next
        }
        

        var slow = head
        var prev : ListNode? = null 
        while(fast?.next != null) {
            prev = slow
            slow = slow?.next
            fast = fast?.next
        }
    
        prev?.next = slow?.next
        
        return head;
    }
}      
  
