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
    #define pp pair<TreeNode*,pair<int,int>> 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {{}};
        vector<vector<int>> ans;
        queue<pp> q;
        map<int,map<int,vector<int>>> mpp;
        q.push({root,{0,0}});
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                int col = curr.second.first;
                int row = curr.second.second;
                mpp[col][row].push_back(node->val);
                if(node->left) q.push({node->left,{col-1,row+1}});
                if(node->right) q.push({node->right,{col+1,row+1}});
            }
        }
        for(auto col:mpp){
            vector<int> v;
            for(auto row:col.second){
                sort(row.second.begin(),row.second.end());
                for(auto x:row.second){
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};