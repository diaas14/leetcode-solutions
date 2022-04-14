/**
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. 
 * The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
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
    public ListNode deleteDuplicates(ListNode head) {
        head = new ListNode(-1, head);
        ListNode temp = head.next, prev = head;
        while (temp != null && temp.next != null) {
            ListNode temp2 = temp.next;
            while (temp2 != null && temp.val == temp2.val) {
                temp2 = temp2.next;
            }
            if (temp2 == temp.next) {
                prev = temp;
                temp = temp.next;
            }
            else {
                prev.next = temp2;
                temp = temp2;
            }
        }
        return head.next;
    }
}
