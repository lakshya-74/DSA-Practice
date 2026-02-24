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
    int rec(TreeNode* root,int x){
        if(root==NULL) return 0;
        x = 2*x + root->val;
        if(root->left==NULL && root->right==NULL) return x;
        return rec(root->left,x) + rec(root->right,x);
    }
    int sumRootToLeaf(TreeNode* root) {
        return rec(root,0);
    }
};