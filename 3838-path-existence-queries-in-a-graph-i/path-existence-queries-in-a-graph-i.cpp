class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            // int lo = i+1;
            // int hi = n-1;
            // while(lo<=hi){
            //     int mid = lo + (hi-lo)/2;
            //     if((nums[mid]-nums[i])>maxDiff){
            //         hi = mid-1;
            //     }
            //     else lo = mid+1;
            // }
            // int next = lo - 1;
            // cout<<next<<" ";
            // for(int k=i+1;k<=next;k++){
            //     if(find(i)!=find(k)) Union(i,k);
            // }
            if((nums[i+1]-nums[i])<=maxDiff) Union(i,i+1);
        }
        cout<<endl;
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            cout<<find(u)<<" "<<find(v)<<endl;
            if(find(u)==find(v)) ans[i] = true; 
        }
        return ans;
    }
};