class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans =0;
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            else count--;
            if(count<0){
                ans++;
                count =0;
            }
        }
        return ans + count;
    }
};