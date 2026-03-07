class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        map<char,int> mpp;
        mpp['a'] = -1;
        mpp['b'] = -1;
        mpp['c'] = -1;
        for(int i=0;i<n;i++){
            mpp[s[i]] = i;
            if(min(mpp['a'],min(mpp['b'],mpp['c']))!=-1){
               ans += 1 + min(mpp['a'],min(mpp['b'],mpp['c']));   
            }
        }
        return ans;
    }
};