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
    int minimumOperations(TreeNode* root) {
        int ans =0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<pair<int,int>> arr;
            int idx = 0;
            while(sz--){
                auto curr= q.front();
                q.pop();
                arr.push_back({curr->val,idx++});
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            int curr = 0;
            sort(arr.begin(),arr.end());
            int n = arr.size();
            vector<int> visited(n,false);
            for(int i=0;i<n;i++){
                if(visited[i] || arr[i].second==i) continue;
                int j = i;
                int cycle = 0;
                while(!visited[j]){
                    visited[j] = true;
                    j = arr[j].second;
                    cycle++;
                }
                curr += cycle -1;
            }
            ans += curr;
        }
        return ans;
    }
};