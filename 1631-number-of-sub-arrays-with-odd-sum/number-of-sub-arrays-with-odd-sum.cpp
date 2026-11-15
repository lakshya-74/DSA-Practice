class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        ll sum = 0;
        int o = 0, e = 1;
        ll ans = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum&1){
                o++;
                ans = (ans+e)%mod;
            }
            else{
                e++;
                ans = (ans+o)%mod;
            }
        }
        return ans%mod;
    }
};