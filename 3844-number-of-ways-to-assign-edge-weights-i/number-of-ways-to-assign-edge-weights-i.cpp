class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    long long power(long long a,long long b){
        long long res = 1;
        while(b){
            if(b&1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> visited(n+1,0);
        q.push(1);
        visited[1] = 1;
        int h = 0;
        while(!q.empty()){
            int sz = q.size();
            h++;
            while(sz--){
                int curr = q.front();
                q.pop();
                for(auto x:adj[curr]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
        }
        h--;
        cout<<h;
        vector<pair<int,int>> v;
        for(int i=1;i<=h;i+=2) v.push_back({i,h-i});
        int ans = 0;
    
        vector<long long> fact(h+1),invFact(h+1);
        fact[0] = 1;
        for(int i=1;i<=h;i++)
            fact[i] = (fact[i-1] * i)%mod;

        invFact[h] = power(fact[h], mod-2);
        for(int i=h-1;i>=0;i--)
            invFact[i] = invFact[i+1]*(i+1)%mod;
        for(int i=0;i<v.size();i++){
            ll a = v[i].first;
            ll b = v[i].second;
            long long ways =fact[h] * invFact[a] % mod * invFact[b] % mod;
            ans = (ans + ways)%mod;
        }
        return ans;
    }
};