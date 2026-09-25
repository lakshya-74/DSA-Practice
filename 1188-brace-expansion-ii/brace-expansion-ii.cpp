class Solution {
public:
    int idx = 0;
    set<string> getUnit(string& exp){
        set<string> ans;
        if(exp[idx]=='{'){
            idx++;
            ans = performUnion(exp);
        }
        else{
            ans = {string(1, exp[idx])};
        }
        idx++;
        return ans;
    }
    set<string> performcont(string& exp){
        set<string> ans = {""};
        while(idx<exp.size() && (exp[idx]=='{' || isalpha(exp[idx]))){
            set<string> temp = getUnit(exp);
            set<string> con;
            for(const auto& left:ans){
                for(const auto& right:temp){
                    con.insert(left+right);
                }
            }
            ans = con;
        }
        return ans;
    }
    set<string> performUnion(string& exp){
        set<string> ans;
        while(1){
            set<string> temp = performcont(exp);
            ans.insert(begin(temp),end(temp));
            if(idx<exp.size() && exp[idx]==',') idx++;
            else break;
        }
        return ans;
    }
    vector<string> braceExpansionII(string exp) {
        set<string> st = performUnion(exp);
        vector<string> ans(begin(st),end(st));
        return ans;
    }
};