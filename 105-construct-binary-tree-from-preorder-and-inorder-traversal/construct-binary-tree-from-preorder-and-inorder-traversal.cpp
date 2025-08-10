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
    TreeNode* build(vector<int> &pre , vector<int> &in, int prel, int preh, int inl , int inh){
        if(prel>preh) return NULL;
        TreeNode* root = new TreeNode(pre[prel]);
        if(prel==preh) return root;
        int i = inl;
        while(i<=inh){
            if(in[i]==pre[prel]) break;
            i++;
        }
        int leftcount = i-inl;
        int rightcount = inh-i;
        root->left = build(pre,in,prel+1,prel+leftcount,inl,i-1);
        root->right = build(pre,in,prel+leftcount+1,preh,i+1,inh);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder,inorder,0,n-1,0,n-1);
    }
};