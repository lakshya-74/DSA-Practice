class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        char pre;
        int ans =0;
        int count =0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                pre = s[i];
                st.push('(');
                count++;
            }
            else{
                st.pop();
                count--;
                if(pre=='(') ans += 1<<count;
                pre = s[i];
            }
        }
        return ans;
    }
};