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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using P = pair<int,ListNode*>;

        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto it: lists)
        {
            if(it)
            {
                pq.push({it->val,it});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* save  = dummy;
        ListNode* t = save;

        while(!pq.empty())
        {
            auto node = pq.top().second;
            pq.pop();
            t->next = node;
            t = node;
            if(node->next)
            {
                pq.push({node->next->val,node->next});
            }
        }

        return save->next;
    }
};