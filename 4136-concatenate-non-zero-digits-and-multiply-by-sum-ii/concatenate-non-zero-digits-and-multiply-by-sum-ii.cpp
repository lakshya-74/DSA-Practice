class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        string st = "";
        vector<int> v;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                st += s[i];
                v.push_back(i);
            }
        }
        
        vector<int> ans;
        int mod = 1e9 + 7;
        int sz = v.size();
        vector<long long> pre(sz+1,0), pow(sz+1,1) , prenum(sz+1,0);
        for(int i=1;i<=sz;i++){
            pow[i] = (pow[i-1]*10)%mod;
        }
        for(int i=0;i<sz;i++){
            pre[i+1] = pre[i] + (st[i]-'0');
            prenum[i+1] = (prenum[i]*10 + (st[i]-'0'))%mod;
        }
        for(int i=0;i<n;i++){
            int a = queries[i][0];
            int b = queries[i][1];

            // lower bound
            int lo = 0;
            int hi = sz-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(v[mid]>=a){
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            int lower = lo;
            // upper bound
            lo = 0 , hi = sz-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(v[mid]<=b){
                    lo = mid+1;
                }
                else hi = mid-1;
            }

            int upper = hi;

            long long sum = (pre[upper+1] - pre[lower] + mod)%mod;
            long long num = (prenum[upper+1] - (prenum[lower]*pow[upper-lower+1])%mod + mod)%mod;
            
            ans.push_back((sum*num)%mod);
        }
        return ans;
    }
};