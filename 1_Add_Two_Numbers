/**
 * Question:
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *sum = nullptr, *temp = nullptr;
        
        while (carry || l1 || l2) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            } 
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            if (!sum) {
                sum = new ListNode(carry % 10);
                temp = sum;
            } else {
                temp->next = new ListNode(carry % 10);
                temp = temp->next;
            }
            carry /= 10;
        }
        return sum;
    }
};
