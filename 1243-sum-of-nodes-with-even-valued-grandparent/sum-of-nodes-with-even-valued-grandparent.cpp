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
    void traverse(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mpp){
        if(root==NULL) return;
        if(root->left){
            mpp[root->left] = root;
            traverse(root->left,mpp);
        }
        if(root->right){
            mpp[root->right] = root;
            traverse(root->right,mpp);
        }
    }
    int trav(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mpp){
        if(root==NULL) return 0;
        if(mpp.find(root)!=mpp.end()){
            TreeNode* parent = mpp[root];
            if(mpp.find(parent)!=mpp.end() && (mpp[parent]->val)%2==0){
                return root->val + trav(root->left,mpp) + trav(root->right,mpp);
            }
        }
        return trav(root->left,mpp) + trav(root->right,mpp); 
    }
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> mpp;
        traverse(root,mpp);
        return trav(root,mpp);
    }
};