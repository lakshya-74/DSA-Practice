class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        vector<int> visited(n,0);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string s = q.front();
                q.pop();
                if(s==endWord) return ans;
                for(int i=0;i<n;i++){
                    int diff = 0;
                    for(int j=0;j<s.size();j++){
                        if(s[j]!=wordList[i][j]) diff++;
                        if(diff>1) break;
                    }
                    if(diff==1 && !visited[i]){
                        visited[i] = 1;
                        q.push(wordList[i]);
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};