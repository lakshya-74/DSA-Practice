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
    int func(TreeNode* root , int& ans){
        if(root==NULL) return 0;
        int leftsum = max(0,func(root->left,ans)); 
        // negative num. se bachne ke liye max 0 kau se kr rhe hai means ki 
        // -ve sum lu usse accha ki mai uss side aage hi na bdhuu
        int rightsum = max(0,func(root->right,ans));
        ans = max(ans,root->val + leftsum + rightsum);
        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        func(root,ans);
        return ans;
    }
};