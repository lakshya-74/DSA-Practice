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
    void path(TreeNode* root,long long sum,int &count){
        if(root==NULL) return;
        if((long long)(root->val)==sum) count++;
        path(root->left,sum-(long long)(root->val),count);
        path(root->right,sum-(long long)(root->val),count);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count =0;
        path(root,targetSum,count);
        count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
        return count;
    }
};