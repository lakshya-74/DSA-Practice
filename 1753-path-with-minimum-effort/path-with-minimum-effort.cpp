class Solution {
public:
    #define pp pair<int,pair<int,int>> 
    int minimumEffortPath(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        priority_queue<pp,vector<pp> ,greater<pp>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> ans(n,vector<int>(m,1e8));
        ans[0][0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(max(d,abs(nums[ni][nj]-nums[i][j]))<ans[ni][nj]){
                        ans[ni][nj] = max(d,abs(nums[ni][nj]-nums[i][j]));
                        pq.push({ans[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return ans[n-1][m-1];
    }
};