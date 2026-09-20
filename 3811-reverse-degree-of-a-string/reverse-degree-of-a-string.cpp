class Solution {
public:
    int reverseDegree(string s) {
        int sum =0 ;
        for(int i=0;i<s.size();i++){
            int curr = 26 - (s[i]-'a');
            sum += curr*(i+1);
        }
        return sum;
    }
};