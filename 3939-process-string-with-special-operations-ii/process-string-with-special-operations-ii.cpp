class Solution {
public:
    char processStr(string s, long long k) {
        long long l = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') l++;
            else if(s[i]=='*' && l>0) l--;
            else if(s[i]=='#') l += l;
        }
        if(k>=l) return '.';
        int i = s.size()-1;
        while(i>=0){
            if(s[i]>='a' && s[i]<='z'){
                l--;
            }
            else if(s[i]=='#'){
                l = l/2;
                if(k>=l) k = k-l;
            }
            else if(s[i]=='%'){
                k = l-k-1;
            }
            else{
                l++;
            }
            if(l==k) return s[i];
            i--;
        }
        return '.';
    }
};