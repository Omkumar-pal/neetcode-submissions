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
    ListNode* reverseList(ListNode* head) {
        vector<int> temp;
        
        ListNode *ptr = head;
        while(ptr != nullptr){
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }

        ptr = head;
        for(int i = temp.size()-1; i >= 0; i--){
            ptr->val = temp[i];
            ptr = ptr->next;
        }

        return head;


    }
};
