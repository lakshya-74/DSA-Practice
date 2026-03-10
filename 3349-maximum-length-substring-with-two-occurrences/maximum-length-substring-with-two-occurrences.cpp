class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0 , r= 0, ans = 0;
        int n = s.size();
        vector<char> v(26,0);
        while(r<n){
            v[s[r]-'a']++;
            while(v[s[r]-'a']>2){
                v[s[l]-'a']--;
                l++;
            }
            if(v[s[r]-'a']<=2) ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};