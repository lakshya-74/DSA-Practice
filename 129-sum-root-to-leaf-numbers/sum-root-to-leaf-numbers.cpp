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
    void leaf(TreeNode* root,int &tsum, int sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            tsum += (sum*10)+root->val;
            return; 
        }
        leaf(root->left,tsum,(sum*10)+root->val);
        leaf(root->right,tsum,(sum*10)+root->val);
    }
    int sumNumbers(TreeNode* root) {
        int tsum =0;
        leaf(root,tsum,0);
        return tsum;
    }
};