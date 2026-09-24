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
    TreeNode* build(vector<int>& in , int ins , int ine , vector<int>& post , int posts , int poste , map<int,int>& mpp){
        if(ins>ine || posts>poste) return NULL;
        int inidx = mpp[post[poste]];
        int len = inidx - ins;
        TreeNode* root = new TreeNode(post[poste]);
        root->left = build(in,ins,inidx-1,post,posts,posts+len-1,mpp);
        root->right = build(in,inidx+1,ine,post,posts+len,poste-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(inorder ,0,inorder.size()-1, postorder,0, postorder.size()-1,mpp);
        return root;
    }
};