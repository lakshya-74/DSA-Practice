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
    void levelorder(TreeNode* root,vector<vector<int>>& ans, int level){
        if(root==NULL) return;
        ans[level].push_back(root->val);
        levelorder(root->left,ans,level+1);
        levelorder(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n);
        levelorder(root,ans,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};