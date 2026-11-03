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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        
        ListNode*temp = head;
        int sz = 0;
        while(temp){
            sz++;
            temp = temp->next;
        }

        int steps = sz-n+1;

        ListNode*p = head;
        ListNode*q = nullptr;
        ListNode*r = nullptr;
        int step_cnt = 0;
        while(step_cnt < steps){
            r = q;
            q = p;
            p = p->next;
            step_cnt++;
        }


        if (!r) return p;

        q->next = nullptr;
        r->next = p;
        
        q = p;
        if (p){
            p = p->next;
        }else {
            p = nullptr;
        }

        

        return head;
    }
};
