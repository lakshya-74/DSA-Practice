class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0;
        for(int i=0;i<s.size();i++){
            int val = s[i] - '0';
            int c = min(abs(curr-val),10-max(val,curr)+min(val,curr));
            curr = val;
            ans += c;
        }
        return ans;
    }
};