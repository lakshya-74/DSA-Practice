class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int curr = 1;
        int pre = 0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) curr++;
            else{
                ans += min(curr,pre);
                pre = curr;
                curr = 1;
            }
        }
        ans += min(curr,pre);
        return ans;
    }
};