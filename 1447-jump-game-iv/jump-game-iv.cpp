class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        int ans = 0;
        queue<int> q;
        vector<int> visited(n,0);
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                if(curr==n-1) return ans;
                visited[curr] = 1;
                if(curr+1<n && !visited[curr+1]) q.push(curr+1);
                if(curr-1>=0 && !visited[curr-1]) q.push(curr-1);
                for(auto x:mpp[nums[curr]]){
                    if(!visited[x]) q.push(x);
                }
                mpp[nums[curr]].clear();
            }
            ans++;
        }
        return ans;
    }
};