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
    #define ll long long 
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,1});
        ll ans =0;
        while(!q.empty()){
            ll rel = q.front().second;
            ll sz = q.size();
            ll f = 1e9;
            ll l = -1;
            while(sz--){
                auto curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                ll val = curr.second - rel;
                f = min(f,val);
                l = max(l,val);
                if(node->left){
                    q.push({node->left,2*val});
                }
                if(node->right){
                    q.push({node->right,2*val+1});
                }
            }
            ans = max(ans,l-f+1);
        }
        return ans;
    }
};