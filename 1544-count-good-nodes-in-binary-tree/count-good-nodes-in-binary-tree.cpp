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
    int rec(TreeNode* root,int mx){
        if(root==NULL) return 0;
        if(root->val>=mx) return 1 + rec(root->left,max(root->val,mx)) + rec(root->right,max(root->val,mx));
        return rec(root->left,mx) + rec(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        return rec(root,-1e5);
    }
};