/**
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
    bool isPalindrome(ListNode* head) {
        // finding the middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // if the no. of the node is odd
        if (fast != nullptr) {
            slow = slow->next;
        }

        // reverse the end half
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while (slow != nullptr) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // comparing the first half and the end half
        fast = head;
        head = prev;
        while (head && fast) {
            if (head->val != fast->val) {
                return false;
            }
            head = head->next;
            fast = fast->next;
        }
        return true;
    }
};