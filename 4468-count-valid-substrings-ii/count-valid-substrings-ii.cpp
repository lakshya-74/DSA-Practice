class Solution {
public:
    #define ll long long 
    long long countValidSubstrings(string s) {
        int n = s.size();
        ll ans = 0;
        int l = -1 , r = 0;
        int lasta = -1;
        int best = -1;
        while(r<n){
            if(s[r]=='a') lasta= r;
            if(s[r]=='b' && lasta!=-1) best = max(best,lasta);
            if(s[r]=='c' && best!=-1) l = max(l,best);
            ans += r-l;
            r++;
        }
        return ans;
    }
};