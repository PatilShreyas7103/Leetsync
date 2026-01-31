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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
        {
            return head;
        }
        if(head->next==NULL)
        {
            // single node
            return  head;
        }
        if(head->next->next==NULL)
        {
            // two nodes
            ListNode* temp = head->next;
            temp->next = head;
            head->next = NULL;
            return temp;
        }

        ListNode* temp = head;
        ListNode* curr = head->next;

        while(curr)
        {
            int k = temp->val;
            int k2 = curr->val;
            temp->val = k2;
            curr->val = k;
            if(temp->next)
            {
                temp = temp->next->next;
            }
            if(curr->next)
            {
                curr = curr->next->next;
            }
            else
            {
                break;
            }
        }

        return head;
    }
};