class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int pre = -1;
        int curr = 0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') count++;
            else count--;
            if(count==0){
                for(int j=pre+2;j<i;j++){
                        ans += s[j];
                }
                pre = i;
            }
        }
        return ans;
    }
};