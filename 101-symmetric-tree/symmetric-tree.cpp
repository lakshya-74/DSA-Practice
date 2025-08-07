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
    bool check(TreeNode* a , TreeNode* b){
        if(a==NULL && b==NULL) return true;
        if(a==NULL || b==NULL) return false;
        if(a->val != b->val) return false;
        return check(a->left,b->left) && check(a->right,b->right);
     }
    TreeNode* inverse(TreeNode* root){
        if(root==NULL) return root;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        inverse(root->left);
        inverse(root->right);
        return root;
     }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        inverse(root->left);
        bool flag = check(root->left,root->right);
        return flag;
    }
};