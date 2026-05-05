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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp =head;
        int len =0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        if(len==0) return NULL;
        k = k%len;
        if(k==0) return head;
        temp = head;
        ListNode* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        for(int i=0;i<len-k-1;i++){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};