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
    void reorderList(ListNode* head) {
        vector<int> temp;
        ListNode* ptr = head;

        while(ptr){
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }

        
        int n = temp.size();
        vector<int> ans = temp;
        int k = 1;
        int j = 1;
        bool flag = true;
        while(j < n){
            if (flag){
                ans[j] = temp[n-k];
                j++;
                flag = !flag;
            }else {
                ans[j] = temp[k];
                k++;
                j++;
                flag = !flag;
            }
        }
        ptr = head;
        for(auto it : ans){
            ptr-> val = it;
            ptr = ptr->next; 
        }

        return;



    }
};
