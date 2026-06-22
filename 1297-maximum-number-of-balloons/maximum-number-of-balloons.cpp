class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(int i=0;i<text.size();i++){
            mpp[text[i]]++;
        }
        int ans = INT_MAX;
        string s = "balon";
        for(int i=0;i<s.size();i++){
            if(s[i]=='l' || s[i]=='o'){
                ans = min(ans,mpp[s[i]]/2);
            }
            else ans = min(ans,mpp[s[i]]);
        }
        return ans;
    }
};