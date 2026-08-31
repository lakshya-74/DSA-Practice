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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return {-1,-1};
        ListNode* temp = head->next;
        ListNode* pre = head;
        int idx = 1;
        vector<int> arr;
        while(temp->next != NULL){
            if((temp->val>pre->val && temp->val>temp->next->val) || (temp->val<pre->val && temp->val<temp->next->val)){
                arr.push_back(idx);
            }
            idx++;
            pre = temp;
            temp = temp->next;
        }
        if(arr.size()<2) return {-1,-1};
        int mnlen = INT_MAX;;
        for(int i=0;i<arr.size()-1;i++){
            mnlen = min(mnlen,arr[i+1]-arr[i]);
        }
        return {mnlen,arr[arr.size()-1]-arr[0]};
    }
};