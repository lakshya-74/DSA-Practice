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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int s = 0;
            while(sz--){
                auto curr = q.front();
                q.pop();
                s += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            sum.push_back(s);
        }
        q.push(root);
        root->val = 0;
        int c = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int csum = 0;
                if(curr->left){
                    csum += curr->left->val;
                }
                if(curr->right){
                    csum += curr->right->val;
                }
                
                if(curr->left){
                    curr->left->val = sum[c+1] - csum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = sum[c+1] - csum;
                    q.push(curr->right);
                }
            }
            c++;
        }
        return root;
    }
};