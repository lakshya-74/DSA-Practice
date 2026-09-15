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
class FindElements {
public:
    // TreeNode* root;
    unordered_set<int> st;
    void traverse(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            root->left->val = 2*(root->val) + 1;
            st.insert(root->left->val);
            traverse(root->left);
        }
        if(root->right){
            root->right->val = 2*(root->val) + 2;
            st.insert(root->right->val);
            traverse(root->right);
        }
    }
    // bool trav(TreeNode* root, int t){
    //     if(root==NULL) return false;
    //     if(root->val==t) return true;
    //     return trav(root->left,t) || trav(root->right,t);
    // }
    FindElements(TreeNode* root) {
        // this->root = root;
        root->val = 0;
        st.insert(0);
        traverse(root);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */