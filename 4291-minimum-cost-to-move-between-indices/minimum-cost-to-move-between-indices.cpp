class Solution {
public:
    #define ll long long
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        closest[0] = 1;
        closest[n-1] = n-2;
        for(int i=1;i<n-1;i++){
            int x = abs(nums[i]-nums[i-1]);
            int y = abs(nums[i]-nums[i+1]);
            if(x<=y) closest[i] = i-1;
            else closest[i] = i+1;
        }
        vector<ll> f(n,0);
        for(int i=1;i<n;i++){
            if(closest[i-1]==i){
                f[i] = f[i-1] + 1;
            }
            else f[i] = f[i-1] + nums[i]-nums[i-1];
        }
        vector<ll> b(n,0);
        for(int i=n-2;i>=0;i--){
            if(closest[i+1]==i){
                b[i] = b[i+1] + 1;
            }
            else b[i] = b[i+1] + nums[i+1]-nums[i];
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l<=r){
                ans[i] = f[r] - f[l];
            }
            else ans[i] = b[r] - b[l];
        }
        return ans;
    }
};