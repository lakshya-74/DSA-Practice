/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> registered; // vector of nodes to check all the nodes are created only one time
    void dfs(Node* actual , Node* clone){
        for(auto n: actual->neighbors){
            if(registered[n->val]==NULL){
                Node* newNode = new Node(n->val);
                registered[n->val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs(n,newNode);
            }
            else{
                clone->neighbors.push_back(registered[n->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        registered.resize(110,NULL);
        Node* clone = new Node(node->val);
        registered[node->val] = clone;
        dfs(node,clone);
        return clone;
    }
};