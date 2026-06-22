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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        int carry = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;

        while(a || b){
            int sum = 0;
            sum+= carry;
            if(a)
            {
                sum+= a->val;
                a = a->next;
            }
            if(b)
            {
                sum+= b->val;
                b = b->next;
            }
            int key = sum%10;
            carry = sum/10;
            curr->next = new ListNode(key);
            curr = curr->next;
        }

        if(carry)
        {
            curr->next = new ListNode(1);
        }

        return ans->next;
    }
};