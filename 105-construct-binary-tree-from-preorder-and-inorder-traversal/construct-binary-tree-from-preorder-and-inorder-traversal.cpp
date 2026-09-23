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
    TreeNode* build(vector<int>& pre , int pres, int pree , vector<int>& inorder , int ins , int ine , map<int,int>& mpp){
        if(pres>pree || ins>ine) return NULL;
        TreeNode* root = new TreeNode(pre[pres]);
        int inidx = mpp[pre[pres]];
        int sz = inidx - ins;
        root->left = build(pre,pres+1,pres+sz,inorder,ins,inidx-1,mpp);
        root->right = build(pre,pres+sz+1,pree,inorder,inidx+1,ine,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<preorder.size();i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder,0,preorder.size()-1,inorder ,0,inorder.size()-1,mpp);
        return root;
    }
};