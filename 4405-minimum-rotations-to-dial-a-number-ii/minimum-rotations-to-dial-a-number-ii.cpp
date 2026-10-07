class Solution {
public:
    int minRotations(int n, string s) {
        int mx_diff = 0;
        int idx = -1;
        int pre = 0;
        for(int i=0;i<s.size();i++){
            int val = s[i] - '0';
            int c = min(abs(val-pre),10-max(val,pre)+min(val,pre));
            int val2 = s[n-1] - '0';
            int c1 = min(abs(val2-pre),10-max(val2,pre)+min(val2,pre));
            if(c>c1 && (c-c1)>mx_diff){
                mx_diff = c-c1;
                idx = i;
            }
            pre = val;
        }
        if(idx!=-1) reverse(s.begin()+idx,s.end());
        cout<<s;
        int ans =0;
        pre = 0;
        for(int i=0;i<s.size();i++){
            int val = s[i] - '0';
            int c = min(abs(val-pre),10-max(val,pre)+min(val,pre));
            ans += c;
            pre = val;
        }
        return ans;
    }
};