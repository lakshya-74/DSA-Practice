class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;
        int count =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') count++;
            else count--;
            if(abs(count)<=1) ans++;
        }
        return ans;
    }
};