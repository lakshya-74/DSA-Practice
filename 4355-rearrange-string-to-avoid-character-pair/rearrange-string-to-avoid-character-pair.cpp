class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n = s.size();
        string ans;
        ans.resize(n);
        int i=0,j=n-1;
        for(int k=0;k<n;k++){
            if(s[k]==x) ans[j--] = s[k];
            else if(s[k]==y) ans[i++] = s[k];
        }
        for(int k=0;k<n;k++){
            if(s[k]!=x && s[k]!=y) ans[i++] = s[k]; 
        }
        return ans;
    }
};