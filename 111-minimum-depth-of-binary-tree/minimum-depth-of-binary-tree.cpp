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
    void leafnode(TreeNode* root,int &minval,int val){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            minval = min(minval,val+1);
            return;
        }
        leafnode(root->left,minval,val+1);
        leafnode(root->right,minval,val+1);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int minval = INT_MAX;
        leafnode(root,minval,0);
        return minval;
    }
};