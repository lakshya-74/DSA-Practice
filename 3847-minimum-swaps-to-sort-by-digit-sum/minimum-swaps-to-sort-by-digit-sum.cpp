class Solution {
public:
    #define ll long long 
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> v(n);
        for(int i=0;i<n;i++){
            ll curr = 0;
            int x = nums[i];
            while(x>0){
                curr += x%10;
                x /= 10;
            }
            v[i] = {curr,nums[i],i};
        }
        int ans  =0;
        sort(v.begin(),v.end());
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i] || v[i][1]==nums[i]) continue;
            int sz = 0;
            int j = i;
            while(!visited[j]){
                visited[j] = true;
                j = v[j][2];
                sz++;
            }
            if(sz>1) ans += sz-1;
        }
        return ans;
    }
};