/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    
    public ListNode reverseLinkedlist(ListNode head){
        ListNode current = head;
        ListNode next = null;
        ListNode prev = null;
        
        while(current != null){
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    public ListNode middle(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow;
    }
    
    public boolean isPalindrome(ListNode head) {
        ListNode middle = middle(head);
        ListNode reversedSecondHalf = reverseLinkedlist(middle);
        
        while(reversedSecondHalf != null){
            if(reversedSecondHalf.val != head.val){
                return false;
            }
            reversedSecondHalf = reversedSecondHalf.next;
            head = head.next;
        }
        
        return true;
    }
}


// 84 / 84 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// Memory Usage: 49.5 MB
