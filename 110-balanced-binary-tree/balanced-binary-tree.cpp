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
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(helper(root->left),helper(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left = helper(root->left);
        int right = helper(root->right);
        if(abs(left-right)>1) return false;

        // upto to this this checks for only one time but we have
        // check for each node so go inside the tree till NULL
        // and return false diff>1 for any of the node
        
        bool check1 = isBalanced(root->left);
        if(!check1) return false;
        bool check2 = isBalanced(root->right);
        if(!check2) return false;
        return true;
    }
};