class Solution {
public:
    #define ll long long
    // ll findh(vector<int>& parent,vector<ll>& depth){
    //     int ans = 1;
    //     for(int i=1;i<parent.size();i++){
    //         int x = parent[i];
    //         int curr = 1;
    //         while(x!=-1){
    //             curr++;
    //             x = parent[x];
    //         }
    //         depth[i] = curr;
    //         ans = max(ans,curr);
    //     }
    //     return ans;
    // }
    void buildt(vector<int>& parent , vector<vector<int>>& adj){
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
    }
    void dfs(int curr , int d , vector<vector<int>>& adj,vector<ll>& depth,int& h){
        depth[curr] = d;
        h = max(h,d);
        for(auto x:adj[curr]){
            dfs(x,d+1,adj,depth,h);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<ll> depth(n,1);
        // ll h = findh(parent,depth);
        vector<vector<int>> adj(n);
        buildt(parent,adj);
        int h = 1;
        dfs(0,1,adj,depth,h);
        ll ans = 1LL * nums[0] * h;
        for(int i=1;i<n;i++){
            int x = parent[i];
            ans += 1LL * nums[i] * (h-depth[i]+1);
        }
        return ans;
    }
};