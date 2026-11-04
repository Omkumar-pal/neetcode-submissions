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
        if (!head) return nullptr;
        unordered_map<Node*, int>mp;
        vector<pair<int,int>> list;

        Node* ptr = head;

        // having node, idx for O(n) lookup;
        int idx = 0;
        while(ptr){
            mp[ptr] = idx;
            idx++;
            ptr = ptr->next;
        }

        // list with value, randomidx;
        ptr = head;
        while(ptr){ 
            int randomidx = -1;
            
            if (ptr->random){
                randomidx = mp[ptr->random];
            }
            list.push_back({ptr->val, randomidx});
            ptr = ptr->next;
        }

        // node with new node  address & idx account for 
        vector<Node*> node;

        // created every node and stored its addr on node list.

        for(int i = 0; i< list.size(); i++){
            Node*curr = new Node(list[i].first);
            node.push_back(curr);
        }
        Node* headnode = node[0];
        // my new nodes are now connected.
        for(int i = 0; i < list.size(); i++){
            
            Node* tail = node[i];

            if (i > 0){
                node[i-1]->next = node[i];
            }
        }
        Node* temp = headnode;
        // placing random pointer correctly;
        for(int i = 0; i< list.size(); i++){

            if (list[i].second != -1){
                temp->random = node[list[i].second];
            }
            temp = temp->next;
        }
        return headnode;
    }
};
