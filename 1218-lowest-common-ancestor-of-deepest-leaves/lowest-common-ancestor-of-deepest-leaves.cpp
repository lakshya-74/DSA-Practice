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
    int find_height(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(find_height(root->left),find_height(root->right));
    }
    TreeNode* lca(TreeNode* root,int height , int level){
        if(root==NULL) return NULL;
        if(level==height-1) return root;
        TreeNode* left = lca(root->left,height,level+1);
        TreeNode* right = lca(root->right,height,level+1);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = find_height(root); 
        return lca(root,height,0);
        
    }
};