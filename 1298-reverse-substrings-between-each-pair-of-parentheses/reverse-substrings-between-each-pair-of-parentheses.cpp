class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> pair(n);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int j = st.top();
                st.pop();
                pair[j] = i;
                pair[i] = j;
            }
        }
        int i =0;
        int dir = 1;
        string ans = "";
        while(i>=0 && i<n){
            if(s[i]=='(' || s[i]==')'){
                i = pair[i];
                dir *= -1;
            }
            else ans += s[i];
            i += dir;
        }
        return ans;
    }
};