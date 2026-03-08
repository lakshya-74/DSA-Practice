class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string st = s;
        sort(st.begin(),st.end());
        char c1 ='z' ,  c2='a';
        for(int i=0;i<n;i++){
            if(s[i]<c1){
                c1 = s[i];
            }    
            if(s[i]>c2){
                c2 = s[i];
            }    
        }
        if(st==s) return 0;
        if(n==2) return -1;
        if(c1==s[0] || c2==s[n-1]) return 1;
        if(c1==s[n-1] && c2==s[0]){
            for(int i=1;i<n-1;i++){
                if(s[i]==c1 || s[i]==c2) return 2;
            }
            return 3;
        }
        return 2;
    }
};