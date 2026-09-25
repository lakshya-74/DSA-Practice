/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                if(curr==NULL){
                    s += "N,";
                }
                else{ 
                    s += to_string(curr->val) + ",";
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        int i = 0;
        int j = data.find(',',i);
        string val = data.substr(i,j-i);
        i = j+1;
        if(val=="N") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            j = data.find(',',i);
            val = data.substr(i,j-i);
            i = j+1;
            if(val=="N") curr->left = NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(val));
                curr->left = temp;
                q.push(temp);
            }
            j = data.find(',',i);
            val = data.substr(i,j-i);
            i = j+1;
            if(val=="N") curr->right = NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(val));
                curr->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));