class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0 , r = 0 , ans = 0;
        int maxfreq = 0;
        // logic --> for any length how i can i get my answer -> if i do (len-maxfreq) it shows how many characters you need to swap for a particular length and if it is <=k then only i can consider it to my maxlen else i have to decrese my window size
        map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            if(mpp[s[r]]>maxfreq) maxfreq = mpp[s[r]];
            int currlen = r-l+1;
            if(currlen-maxfreq>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            if(currlen-maxfreq<=k) ans = max(ans,currlen);
            r++;
        }  
        return ans;
    }
};