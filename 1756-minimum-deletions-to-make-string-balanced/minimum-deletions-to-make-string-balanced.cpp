class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> a(n,0) , b(n,0);
        int as = 0;
        int bs = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='b') bs++;
            else as++;
            a[i] = as;
            b[i] = bs;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int x = a[n-1] - a[i];
            if(s[i]=='a'){
                int y = b[i];
                ans = min(ans,x+y);
            }
            else{
                int y = b[i]-1;
                ans = min(ans,x+y);
            }
        }
        return ans;
    }
};