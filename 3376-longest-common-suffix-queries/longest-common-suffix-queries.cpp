class Solution {
public:

    struct Node{
        int ind;
        int next[26];

        Node(){
            ind = -1;
            memset(next, -1, sizeof(next));
        }
    };

    vector<Node> trie;

    Solution(){
        trie.push_back(Node());
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int n = wordsContainer.size();

        for(int i = 0; i < n; i++){

            string& s = wordsContainer[i];

            if(trie[0].ind == -1 ||
               wordsContainer[trie[0].ind].length() > s.length()){

                trie[0].ind = i;
            }

            int node = 0;

            for(int j = s.length() - 1; j >= 0; j--){

                int c = s[j] - 'a';

                if(trie[node].next[c] == -1){

                    trie[node].next[c] = trie.size();

                    trie.push_back(Node());
                }

                node = trie[node].next[c];

                if(trie[node].ind == -1 ||
                   wordsContainer[trie[node].ind].length() > s.length()){

                    trie[node].ind = i;
                }
            }
        }

        vector<int> ans;

        for(string& s : wordsQuery){

            int node = 0;

            for(int j = s.length() - 1; j >= 0; j--){

                int c = s[j] - 'a';

                if(trie[node].next[c] == -1){
                    break;
                }

                node = trie[node].next[c];
            }

            ans.push_back(trie[node].ind);
        }

        return ans;
    }
};