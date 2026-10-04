class Solution {
public:
    bool checkValidString(string s) {
        // int left = 0 , star = 0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='(') left++;
        //     else if(s[i]=='*') star++;
        //     else{
        //         if(left>0) left--;
        //         else if(star>0) star--;
        //         else return false;
        //     }
        // }
        // if(left>0 && left>star) return false;
        // return true;
        stack<int> st;
        stack<int> star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(st.size()) st.pop();
                else if(star.size()) star.pop();
                else return false;
            }
        }
        while(st.size()){
            if(star.empty()) return false;
            if(star.top()>st.top()){
                star.pop();
                st.pop();
            }
            else return false;
        }
        return true;
    }
};