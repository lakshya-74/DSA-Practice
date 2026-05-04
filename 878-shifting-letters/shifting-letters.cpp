class Solution {
public:
    #define ll long long
    string shiftingLetters(string s, vector<int>& shifts) {
        string ans = "";
        int n = shifts.size();
        vector<ll> pre(n,0);
        pre[n-1] = shifts[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i] = pre[i+1] + shifts[i]; 
        }
        for(int i=0;i<n;i++){
            ll x = ((s[i]-'a') + pre[i] + 26)%26;
            char c = char(x+'a');
            ans += c;
        }
        return ans;
    }
};