class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans;
        int i=0;
        while(i<(n-2)){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                string s = num.substr(i,3);
                ans = max(ans,s);
            }
            i++;
        }
        return ans;
    }
};