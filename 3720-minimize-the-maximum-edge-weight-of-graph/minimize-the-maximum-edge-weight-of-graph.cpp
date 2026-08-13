class Solution {
public:
    #define pp pair<int,int>
    bool check(int mx,vector<vector<pp>>& adj,int th){
        int n = adj.size();
        vector<int> visited(n,0);
        queue<int> pq;
        pq.push(0);
        while(!pq.empty()){
            auto curr = pq.front();
            pq.pop();
            int node = curr;
            if(visited[node]) continue;
            visited[node] = 1;
            for(auto x:adj[node]){
                if(x.second<=mx && !visited[x.first]) pq.push(x.first);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int th) {
        int mxw = 0;
        vector<vector<pp>> adj(n);
        for(auto x:edges){
            adj[x[1]].push_back({x[0],x[2]});
            mxw = max(mxw,x[2]);
        }
        int lo = 0;
        int hi = mxw;
        int ans = 1e8;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,adj,th)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans==1e8?-1:ans;
    }
};