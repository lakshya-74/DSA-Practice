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
    TreeNode* poi(TreeNode* root){
        TreeNode* p = root->left;
        while(p->right){
            p = p->right; 
        }
        return p;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key){
            // case 1:
            if(root->left==NULL && root->right==NULL) return NULL;
            // case 2:
            if(root->left==NULL || root->right==NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }
            // case 3:
            else{
                TreeNode* pre = poi(root);
                root->val = pre->val;
                // now delete pre. value
                // it is pred. so its in left side of root only
                root->left = deleteNode(root->left,pre->val);
                // and pre is always have case 1 or 2 condition
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else root->right = deleteNode(root->right,key);
        return root;
    }
};