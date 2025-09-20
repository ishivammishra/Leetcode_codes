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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* se = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while (se) {
            ListNode* temp = se->next;
            se->next = prev;
            prev = se;
            se = temp;
        }

        ListNode* fi = head;
        se = prev;
        while (se) {
            ListNode* temp1 = fi->next;
            ListNode* temp2 = se->next;
            fi->next = se;
            se->next = temp1;
            fi = temp1;
            se = temp2;
        }
    }
};