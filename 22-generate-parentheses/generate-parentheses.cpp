class Solution {
public:
    void rec(int a,int b, int n , vector<string>& ans , string s){
        if(b==0){
            ans.push_back(s);
            return;
        }
        if(a>0) rec(a-1,b,n,ans,s+'(');
        if(b>a) rec(a,b-1,n,ans,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(n,n,n,ans,"");
        return ans;
    }
};