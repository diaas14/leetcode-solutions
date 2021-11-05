/**
 * Question:
 * Given the head of a linked list, rotate the list to the right by k places.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || !k) return head;
        int len = 1;
        ListNode *temp = head;
        while (temp->next && ++len)
            temp = temp->next; 
        k = len - k % len;
        // circularly connecting
        temp->next = head;
        while (k--)
            temp = temp->next;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
