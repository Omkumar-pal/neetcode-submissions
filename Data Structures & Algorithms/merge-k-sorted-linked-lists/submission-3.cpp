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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i< lists.size(); i++){
            ListNode *ptr = lists[i];
            while(ptr){
                pq.push(ptr->val);
                ptr = ptr->next;
            }
        }
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        ListNode* prv = nullptr;
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            if (!head){
                head = node;
                curr = node;
                prv = node;
            }else {
                curr = node;
                prv->next = curr;
                prv = curr;
            }
        }

        return head;


    }
};
