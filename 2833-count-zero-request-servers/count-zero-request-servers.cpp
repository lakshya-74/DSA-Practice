class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<vector<int>> v;
        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> ans(queries.size());
        sort(logs.begin(),logs.end(),[](vector<int> a,vector<int> b){
            return a[1]<b[1];
        });
        vector<int> c(n+1,0);
        int l=0,r =0;
        int count = 0;
        for(int i=0;i<v.size();i++){
            while(r<logs.size() && logs[r][1]<=v[i][0]){
                if(c[logs[r][0]]==0) count++;
                c[logs[r][0]]++;
                r++;
            }
            while(l<r && logs[l][1]<v[i][0]-x){
                c[logs[l][0]]--;
                if(c[logs[l][0]]==0) count--;
                l++;
            }
            ans[v[i][1]] = n - count; 
        }
        return ans;
        
    }
};