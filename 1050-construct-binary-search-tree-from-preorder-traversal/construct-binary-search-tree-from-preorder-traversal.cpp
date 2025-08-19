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
    void insert(TreeNode* root , int val){
        if(root==NULL) return;
        if(root->val > val){
            if(root->left==NULL){
                TreeNode* a = new TreeNode(val);
                root->left = a;
            }
            else insert(root->left,val);
        }
        else if(root->val < val){
            if(root->right==NULL){
                TreeNode* a = new TreeNode(val);
                root->right = a;
            }
            else insert(root->right,val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
        return root;
    }
};