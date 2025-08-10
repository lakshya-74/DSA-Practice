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
    void path(TreeNode* root,int sum ,bool &flag){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum) flag = true;
            return;
        }
        path(root->left,sum-(root->val),flag);
        path(root->right,sum-(root->val),flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        path(root,targetSum,flag);
        return flag;
    }
};