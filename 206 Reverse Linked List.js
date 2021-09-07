/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
  let current = head;
  let prev = null;
  
  while(current) {
    const next = current.next;
    current.next = prev; // reverse pointers
    prev = current;
    current = next;
  }
  return prev;

};


// Runtime: 80 ms, faster than 59.60% of JavaScript online submissions for Reverse Linked List.
// Memory Usage: 40.6 MB, less than 55.97% of JavaScript online submissions for Reverse Linked List.
