class Solution {
public:
    #define ll long long
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        priority_queue<vector<ll> , vector<vector<ll>> , greater<vector<ll>> >pq1, pq2;
        for(int i=0;i<n;i++){
            // server value , idx
            pq1.push({servers[i],i});
        }
        int m = tasks.size();
        ll t = 0;
        vector<int> ans(m);
        for(int i =0;i<m;){
            while(!pq2.empty() && pq2.top()[0]<=t){
                pq1.push({pq2.top()[1],pq2.top()[2]});
                pq2.pop();
            }
            if(pq1.empty()){
                t = pq2.top()[0];
                continue;
            }
            auto curr = pq1.top();
            pq1.pop();
            ans[i] = curr[1];
            pq2.push({t+tasks[i],curr[0],curr[1]});
            i++;
            t = max(t,(ll)i);
        }
        return ans;
    }
};