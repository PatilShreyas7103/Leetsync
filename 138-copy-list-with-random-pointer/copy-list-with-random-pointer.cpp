/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* t = head;
        if(!head)
        {
            return NULL;
        }
        while(t)
        {
            Node* copy = new Node(t->val);
            copy->next = t->next;
            t->next = copy;
            t = copy->next;
        }

        t = head;
        while(t)
        {
            if(t->random)
            {
                t->next->random = t->random->next;
            }
            t = t->next->next;
        }

        Node* real = head;
        Node* ans = head->next;
        Node* curr = ans;

        while(curr)
        {
            real->next = real->next->next;
            curr->next = curr->next ? curr->next->next: NULL;
            real = real->next;
            curr = curr->next;
        }

        return ans;
    }
};