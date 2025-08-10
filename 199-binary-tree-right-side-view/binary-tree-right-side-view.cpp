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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void preorder(TreeNode* root,vector<int>& ans, int level){
        if(root==NULL) return;
        ans[level] = root->val;
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
        // preorder also works here b/c at the end at each level right most value will come and if ans[level] had diiff. value then it replces
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root));
        preorder(root,ans,0);
        // or you can also do with level order traversal at each level
        // make ans[level] = root->val it also fill the last or rightmost 
        // value only
        return ans;
    }
};