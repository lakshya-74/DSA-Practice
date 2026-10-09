class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int i = 0;
        int n = s.size();
        long long  mx = INT_MAX;
        long long mn = INT_MIN;
        bool neg = false;
        while(i<n && s[i]==' ') i++;
        if(i==n) return 0;
        if(isalpha(s[i])) return 0;
        if(s[i]=='-'){
            neg = true;
            i++;
        }
        else if(s[i]=='+' || s[i]==' ') i++;
        while(i<n && s[i]>='0' && s[i]<='9'){
            int curr = s[i] - '0';
            if(neg &&  1LL*ans*10 + curr > 1LL*abs(mn)){
                return mn;
            }
            else if(!neg && ans>(mx-curr)/10){
                return mx;
            }
            ans = ans*10 + curr;
            i++;
        }
        if(neg){
            if(ans== 1LL*abs(mn)) return mn;
            return -ans;
        }
        return ans;
    }
};