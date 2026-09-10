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
    int countnodes(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + countnodes(root->left) + countnodes(root->right);
    }
    int countsum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val + countsum(root->left) + countsum(root->right);
    }
    int traverse(TreeNode* root){
        if(root==NULL) return 0;
        if(!root->left && !root->right){
            return 1;
        }
        int ans = traverse(root->left);
        ans += traverse(root->right);
        int nodes = countnodes(root);
        int sum  = countsum(root);
        if(sum/nodes==root->val) ans += 1;
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        return traverse(root);
    }
};