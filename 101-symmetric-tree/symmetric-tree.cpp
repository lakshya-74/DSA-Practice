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
    // bool check(TreeNode* a , TreeNode* b){
    //     if(a==NULL && b==NULL) return true;
    //     if(a==NULL || b==NULL) return false;
    //     if(a->val != b->val) return false;
    //     return check(a->left,b->left) && check(a->right,b->right);
    //  }
    // TreeNode* inverse(TreeNode* root){
    //     if(root==NULL) return root;
    //     TreeNode* temp = root->right;
    //     root->right = root->left;
    //     root->left = temp;
    //     inverse(root->left);
    //     inverse(root->right);
    //     return root;
    //  }
    bool check(TreeNode* a , TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;
        return check(a->left,b->right) && check(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {

        // // first inverse the left side so that it becomes similar
        // // and then check for each value of left and right if its different then false
        // if(root==NULL) return true;
        // inverse(root->left);
        // return check(root->left,root->right);
        if(!root) return true;
        return check(root->left,root->right);
    }
};