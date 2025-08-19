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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* a = new TreeNode(val);
            return a;
        }
        if(val<root->val && root->left==NULL){
            TreeNode* a = new TreeNode(val);
            root->left = a;
            return root;
        }
        else if(val>root->val && root->right==NULL){
            TreeNode* a = new TreeNode(val);
            root->right = a;
            return root;
        }
        else if(root->val<val) insertIntoBST(root->right,val);
        else insertIntoBST(root->left,val);
        return root;
    }
};