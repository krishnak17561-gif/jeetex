class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = NULL, *cur = slow->next;
        slow->next = NULL;

        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // Merge two halves
        ListNode *first = head, *second = prev;

        while (second) {
            ListNode *t1 = first->next;
            ListNode *t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};