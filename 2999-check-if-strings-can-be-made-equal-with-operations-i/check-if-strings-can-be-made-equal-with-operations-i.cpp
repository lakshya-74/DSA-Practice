class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<4;i++){
            if(s1[i]==s2[i]) continue;
            if(i>1){
                if(s1[i]==s2[i-2]) continue;
            }
            if(i<2 && s1[i]==s2[i+2]) continue;
            return false;
        }
        return true;
    }
};