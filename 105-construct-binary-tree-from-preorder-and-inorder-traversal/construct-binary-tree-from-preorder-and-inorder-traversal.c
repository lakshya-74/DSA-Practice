/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* create(int x){
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct TreeNode* build(int pre[] , int in[] , int prel , int preh , int inl , int inh){
    if(prel>preh) return NULL;
    struct TreeNode* root = create(pre[prel]);
    if(prel==preh) return root;
    int i = inl;
    while(i<=inh){
        if(in[i]==pre[prel]) break;
        i++;
    }
    int left = i - inl;
    int right = inh - i;
    root->left = build(pre,in,prel+1,prel+left,inl ,i-1);
    root->right = build(pre,in,prel+left+1,preh,i+1,inh);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder,inorder,0,preorderSize-1,0,inorderSize-1);
}