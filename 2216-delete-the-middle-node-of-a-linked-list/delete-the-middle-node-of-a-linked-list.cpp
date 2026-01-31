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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;

        while(temp)
        {
            cnt++;
            temp = temp->next;
        }

        if(cnt==1)
        {
            return NULL;
        }

        temp = head;
        int id = (cnt)/2;
        id--;

        while(id--)
        {
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
    }
};