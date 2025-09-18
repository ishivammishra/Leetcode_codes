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
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while (slow != nullptr) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        fast = head;
        head = prev;
        while (head and fast) {
            if (fast->val != head->val) {
                return false;
            }
            fast = fast->next;
            head = head->next;
        }
        return true;
    }
};