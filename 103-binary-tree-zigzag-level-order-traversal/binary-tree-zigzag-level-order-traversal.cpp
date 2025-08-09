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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void helper(TreeNode* root,vector<vector<int>> & ans,int idx){
        if(root==NULL) return;
        ans[idx].push_back(root->val);
        helper(root->left,ans,idx+1);
        helper(root->right,ans,idx+1);        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n);
        helper(root,ans,0);
        for(int i=0;i<n;i++){
            if(i&1){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;

    }
};