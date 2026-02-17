class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0; h<=11;h++){
            for(int m=0;m<=59;m++){
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn){
                    string s1 = to_string(h);
                    string s2 = (m<10?"0":"") + to_string(m);
                    ans.push_back(s1+":"+s2);
                }
            }
        }
        return ans;
    }
};