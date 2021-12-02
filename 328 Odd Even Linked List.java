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
    public ListNode oddEvenList(ListNode head) {
       if(head == null) {
           return head;
       }
        ListNode o = head;
        e = head.next;
        temp = e;
        
        while(o != null && e != null){
            o.next = e.next;
            if(o.next == null) break;
            o = o.next;
            e.next = o.next;
            e = e.next;
        }
        o.next = temp;
        return head;
    }
}
