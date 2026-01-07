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
    int mod = 1e9 + 7;
    #define ll long long
    int calc_sum(TreeNode* root){
        if(root==NULL) return 0;
        ll leftsum = calc_sum(root->left);
        ll rightsum = calc_sum(root->right);
        return root->val + leftsum + rightsum;
    }
    ll inorder(TreeNode* root,ll total,ll& mx){
        if(root==NULL) return 0;
        ll left = inorder(root->left,total,mx);
        ll right = inorder(root->right,total,mx);
        ll sum = root->val + left + right;
        mx = max(mx,(total-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        ll total = calc_sum(root);
        ll mx = 0;
        inorder(root,total,mx);
        return mx%mod;
    }
};