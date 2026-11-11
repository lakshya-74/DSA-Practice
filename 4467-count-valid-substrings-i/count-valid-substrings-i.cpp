class Solution {
public:
    #define ll long long
    long long countValidSubstrings(string s) {
        ll n = s.size();
        ll count = 0;
        int j =0;
        for(int i=0;i<n;i++){
            if(i>1 && s[i-2]=='a' && s[i-1]=='b' && s[i]=='c') j = i-1;
            count += i-j+1;
        }
        return count;
        
    }
};