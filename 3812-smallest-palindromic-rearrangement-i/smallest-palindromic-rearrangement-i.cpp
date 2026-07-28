class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        string ans;
        ans.resize(s.size());
        int i=0 , j = s.size()-1;
        char c;
        for(int k=0;k<26;k++){
            if(v[k]&1){
                c = (k + 'a');
                v[k]--;
            }
            while(v[k]>=2){
                ans[i++] = char(k+97);
                ans[j--] = char(k+97);
                v[k] -= 2;
            }
        }
        if(i==j) ans[i] = c;
        return ans;
    }
};