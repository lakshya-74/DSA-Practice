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
    void helper(TreeNode* root ,map<int,int> &mpp){
        if(root==NULL) return;
        mpp[root->val]++;
        helper(root->left,mpp);
        helper(root->right,mpp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mpp;
        helper(root,mpp);
        int mx = 0;
        vector<int> ans;
        for( auto x:mpp){
            if(x.second>mx){
                mx = x.second;
            }
        }
        for(auto x:mpp){
            if(x.second==mx) ans.push_back(x.first);
        }
        return ans;
    }
};