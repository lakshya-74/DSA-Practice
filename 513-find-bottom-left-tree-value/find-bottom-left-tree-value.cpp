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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right)); 
    }
    int check(TreeNode* root, int h){
        if(root==NULL) return INT_MAX;
        if(h==1) return root->val;
        int a = check(root->left,h-1);
        int b = check(root->right,h-1);
        if(a!=INT_MAX) return a;
        return b;
    }
    int findBottomLeftValue(TreeNode* root) {
        int h = height(root);
        return check(root,h);
    }
};