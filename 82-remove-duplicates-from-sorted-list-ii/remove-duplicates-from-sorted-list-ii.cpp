class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (curr) {
            bool leftUnique = true, rightUnique = true;

            if (prev && prev->val == curr->val)
                leftUnique = false;

            if (next && next->val == curr->val)
                rightUnique = false;

            if (leftUnique && rightUnique) {
                tail->next = curr;
                tail = tail->next;
            }

            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }

        tail->next = nullptr;

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};