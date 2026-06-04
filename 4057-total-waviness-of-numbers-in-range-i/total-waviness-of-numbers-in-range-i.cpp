class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int j=num1;j<=num2;j++){
            string s = to_string(j);
            if(s.size()<3) continue;
            for(int i=1;i<s.size()-1;i++){
                if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])) ans++;
            }
        }
        return ans;
    }
};