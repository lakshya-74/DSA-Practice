class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_set<string> s;
        for(int i=0;i<n-1;i++){
            for(int j= i+1;j<n;j++){
                reverse(words[j].begin(),words[j].end());
                if(words[i]==words[j]) s.insert(words[i]);
            }
        }
        return s.size();
    }
};