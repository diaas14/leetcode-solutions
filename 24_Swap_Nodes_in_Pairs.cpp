/**
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You must solve the problem without modifying the values 
 * in the list's nodes (i.e., only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp1 = head, *temp2;
        
        while (temp1 && temp1->next) {
            temp2 = temp1->next;
            temp1->next = temp2->next;
            temp2->next = temp1;
            
            if (prev)
                prev->next = temp2;
            else
                head = temp2;
            prev = temp1;
            temp1 = temp1->next;
        }
        return head;
    }
};
