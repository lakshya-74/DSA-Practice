class Solution {
public:
    #define ll long long
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mx = nums[n-1];
        vector<ll> f(mx+1,0);
        for(int i=0;i<n;i++) f[nums[i]]++;
        vector<int> v(mx+1,0);
        ll ans=0;
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto x:st){
            if(v[x]!=0 && v[x]<x) continue;
            for(int j=x;j<=mx;j+=x){
                if(!v[j]){
                    v[j] = x;
                }
            }
        }
        for(int i=1;i<=mx;i++){
            if(f[i]>0) ans += v[i]*f[i];
        }
        return ans;
    }
};