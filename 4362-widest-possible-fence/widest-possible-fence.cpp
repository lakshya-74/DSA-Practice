class Solution {
public:
    #define ll long long
    int maximumWidth(vector<int>& nums) {
        unordered_map<ll,ll> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<ll> v;
        for(auto x:mpp){
            v.push_back(x.first);
        }
        unordered_map<ll,ll> check;
        int m = v.size();
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                ll sum = v[i] + v[j];
                if(i==j) check[sum] += mpp[v[i]]/2;
                else{
                    check[sum] += min(mpp[v[i]],mpp[v[j]]);
                }
            }
        }
        ll ans = 0;
        for(auto x:check){
            ans = max(ans,mpp[x.first]+x.second);
        }
        for(auto x:mpp) ans = max(ans,x.second);
        return ans;
    }
};