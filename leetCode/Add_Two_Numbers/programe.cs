/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
    public class Solution {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2, bool next = false) {
        //[2 ,3 ,3]
        //[5 ,5 ,4]
            var val1 = l1?.val ?? 0;
            var val2 = l2?.val ?? 0;
            var sum = val1 + val2 + (next ? 1 : 0);
            var current = sum % 10;
            next = sum >= 10;
            if (l1?.next == null && l2?.next == null)
                return new ListNode(current, next ? new ListNode(1) : null);
            var newNode = AddTwoNumbers(l1?.next, l2?.next, next);
            return new ListNode(current,newNode);
    }
    }