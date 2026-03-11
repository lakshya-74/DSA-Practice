class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int r = 0 , l = 0 , ans = 0;
        int zero =0,one =0;
        while(r<n){
            if(s[r]=='0') zero++;
            else one++;
            while(zero>k && one>k){
                if(s[l]=='0') zero--;
                else one--;
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};