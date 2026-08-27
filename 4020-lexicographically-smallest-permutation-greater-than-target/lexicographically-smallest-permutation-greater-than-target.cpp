class Solution {
public:
    void rec(int idx,string& target, map<char,int>& mpp, string& str, bool& check){
        if(idx>= target.size()){
            check = false;
            return;
        }
        if(check){
            for(auto& x:mpp){
                while(x.second>0){
                    str += x.first;
                    x.second--;
                }
            }
            return;
        }
        if(mpp[target[idx]]){
            mpp[target[idx]]--;
            str += target[idx];
            rec(idx+1,target,mpp,str,check);
            if(check) return;
            mpp[target[idx]]++;
            str.pop_back();
        }
        char mn = '0';
        for(auto& x:mpp){
            if(x.first>target[idx] && x.second){
                mn = x.first;
                break;
            }
        }
        if(mn!='0' && mpp[mn]){
            mpp[mn]--;
            str += mn;
            check = true;
            for(auto& x:mpp){
                while(x.second>0){
                    str += x.first;
                    x.second--;
                }
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        string str=  "";
        bool check = false;
        rec(0,target,mpp,str,check);
        if(!check) return "";
        return str; 
    }
};