class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i = 0 ,j = 0;
        int n = s.size();
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
                j++;
            }
            while(j<n && s[j]!=' ') j++;
            string lett = "";
            while(i<n && i<j){
                if(s[i]!=' ') lett+= s[i];
                i++;
            }
            if(lett!="") st.push(lett);
        }
        string ans = "";
        while(st.size()){
            ans += st.top();
            st.pop();
            if(st.size()) ans += " ";
        }
        return ans;
    }
};