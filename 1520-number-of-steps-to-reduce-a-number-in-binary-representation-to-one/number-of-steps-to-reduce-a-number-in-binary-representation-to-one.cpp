class Solution {
public:
    int numSteps(string s) {
        // int n = 0;
        // int k = 0;
        // for(int i=s.size()-1;i>=0;i--){
        //     n += ((s[i]=='1')?1:0)*(1<<k);
        //     k++;
        // }
        // int ans =0;
        // while(n>1){
        //     if(n&1) n++;
        //     else n /= 2;
        //     ans++;
        // }
        // return ans;
        int count =0;
        for(int i=s.size()-1;i>0;){
            if(s[i]=='0'){
                count++;
                i--;
                continue;
            }
            s[i] = '0';
            int j = i-1;
            while(j>=0 && s[j]=='1'){
                s[j] = '0';
                j--;
            }
            if(j<0){
                s = '1' + s;
                i++;
            }
            else s[j] = '1';
            count++;
        }
        return count;
    }
};