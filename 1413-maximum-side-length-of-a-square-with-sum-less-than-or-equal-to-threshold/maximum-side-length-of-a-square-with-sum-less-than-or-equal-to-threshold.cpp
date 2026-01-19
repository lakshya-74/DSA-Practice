class Solution {
public:
    bool check(int mid, vector<vector<int>>& pre,int t){
        for(int i=0;i<pre.size();i++){
            for(int j=0;j<pre[0].size();j++){
                if(i>=mid-1 && j>=mid-1){
                    int sum = pre[i][j];
                    if(j-mid>=0) sum -= pre[i][j-mid];
                    if(i-mid>=0) sum -= pre[i-mid][j];
                    if(i-mid>=0 && j-mid>=0) sum += pre[i-mid][j-mid];
                    if(sum<=t) return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j] = mat[i][j];
                if(i>0) pre[i][j] += pre[i-1][j];
                if(j>0) pre[i][j] += pre[i][j-1];
                if(i>0 && j>0) pre[i][j] -= pre[i-1][j-1];
            }
        }
        int lo = 0;
        int hi =min(n,m); 
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,pre,threshold)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};