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
        Node* dummy = new Node(0);
        Node* tempd = dummy;
        Node* temp = head;
        while(temp){
            Node* x = new Node(temp->val);
            tempd->next = x;
            tempd = tempd->next;
            temp = temp->next;
        }
        tempd = dummy->next;
        temp = head;
        map<Node*,Node*> mpp;
        while(temp){
            mpp[temp] = tempd;
            tempd = tempd->next;
            temp = temp->next;
        } 
        for(auto x:mpp){
            if(x.first->random != NULL) x.second->random = mpp[x.first->random]; 
        }
        return dummy->next;
    }
};