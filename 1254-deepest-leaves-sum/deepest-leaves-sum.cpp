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
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }
    int count(TreeNode* root,int d){
        if(!root) return 0;
        if(d==1){
            return root->val;
        }
        return count(root->left,d-1) + count(root->right,d-1);
    }   
    int deepestLeavesSum(TreeNode* root){
        int d = depth(root);
        return count(root,d);
    }
};