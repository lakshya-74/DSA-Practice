class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int idx = s[i] - 'a';
            ans = max(ans,(26-idx)%26);
        }
        return ans;
    }
};