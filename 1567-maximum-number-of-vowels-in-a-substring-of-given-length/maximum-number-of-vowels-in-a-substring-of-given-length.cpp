class Solution {
public:
    bool isvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0 ,r = 0; int count = 0;
        int ans = 0;
        while(r<n){
            if(isvowel(s[r])) count++;
            if(r-l+1>k){
                if(isvowel(s[l])) count--;
                l++;
            }
            if(r-l+1==k) ans = max(ans,count);
            r++;
        }
        return ans;
    }
};