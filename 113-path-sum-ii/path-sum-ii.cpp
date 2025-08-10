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
    void path(TreeNode* root,vector<vector<int>>& ans,vector<int> v, int n){
        if(root==NULL) return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            int sum =0;
            for(int i=0;i<v.size();i++){
                sum += v[i];
            }
            if(sum==n) ans.push_back(v);
            v.pop_back();
            return;
        }
        
        path(root->left,ans,v,n);
        path(root->right,ans,v,n);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        path(root,ans,v,targetSum);
        return ans;
    }
};