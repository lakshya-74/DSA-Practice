class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        for(int i=0;i<s.size();){
            if(flag && s[i]=='1') return false;
            while(s[i]=='1'){
                flag = true;
                i++;
            } 
            i++;
        }
        return true;
    }
};