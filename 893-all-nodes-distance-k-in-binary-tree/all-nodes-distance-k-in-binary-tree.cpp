/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #define pp pair<int,int>
    void traverse(TreeNode* root , unordered_map<TreeNode*,TreeNode*>& mpp){
        if(root==NULL) return;
        if(root->left){
            mpp[root->left] = root;
            traverse(root->left,mpp);
        }
        if(root->right){
            mpp[root->right] = root;
            traverse(root->right,mpp); 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        traverse(root,mpp);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> st;
        q.push(target);
        st.insert(target);
        vector<int> ans;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                ans.push_back(curr->val);
                if(curr->left && !st.count(curr->left)){
                    q.push(curr->left);
                    st.insert(curr->left);
                }
                if(curr->right && !st.count(curr->right)){
                    q.push(curr->right);
                    st.insert(curr->right);
                }
                if(curr!=root && !st.count(mpp[curr])){
                    q.push(mpp[curr]);
                    st.insert(mpp[curr]);
                }

            }
            if(k==0){
                return ans;
            }
            k--;
            ans.clear();
        }
        return {};
    }
};