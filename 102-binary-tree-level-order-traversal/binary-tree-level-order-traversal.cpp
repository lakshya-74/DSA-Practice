/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int totallevels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(totallevels(root->left),totallevels(root->right));
    }
    void checkelement(TreeNode* root,int curr,int target,vector<int>&v){
        if(root==NULL) return;
        if(curr==target){
            v.push_back(root->val);
            return;
        }
        checkelement(root->left,curr+1,target,v);
        checkelement(root->right,curr+1,target,v);
    }
    void levels(TreeNode* root,vector<vector<int>> &ans){
        int n = totallevels(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            checkelement(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levels(root,ans);
        return ans;
    }    
};