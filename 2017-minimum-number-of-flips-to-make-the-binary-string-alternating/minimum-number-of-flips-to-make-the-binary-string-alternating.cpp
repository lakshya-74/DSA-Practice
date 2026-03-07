class Solution {
public:
    int check(string s){
        int n = s.size();
        int op1 = 0;
        int op2 = 0;
        for(int i=0;i<n;i++){
            if(i%2==0){ // iss position pr 0 houna hai
                if(s[i]=='1') op1++;
                if(s[i]=='0') op2++;
            }
            else{
                if(s[i]=='0') op1++;
                if(s[i]=='1') op2++;
            }
        }
        return min(op1,op2);
    }
    int minFlips(string st) {
        int n = st.size();
        // string st = s+s; // circular mai bhut kaam ka hai yee
        int l = 0;
        int r= 0;
        int op1 = 0 , op2 = 0;
        int ans = INT_MAX;
        while(r<2*n){
            if(r%2==0){ // iss position pr 0 houna hai
                if(st[r%n]=='1') op1++;
                if(st[r%n]=='0') op2++;
            }
            else{
                if(st[r%n]=='0') op1++;
                if(st[r%n]=='1') op2++;
            }  
            if(r-l+1==n){
                ans = min(ans,min(op1,op2));
                if(l%2==0){
                    if(st[l]=='1') op1--; 
                    else op2--;
                }
                else{
                    if(st[l]=='0') op1--;
                    else op2--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};