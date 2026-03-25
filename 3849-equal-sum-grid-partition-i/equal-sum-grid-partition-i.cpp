class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> hor(n,0) , ver(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hor[i] += grid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                ver[j] += grid[i][j];
            }
        }
        vector<long long> pre(n) , suff(n);
        pre[0] = hor[0];
        suff[n-1] = hor[n-1];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + hor[i];
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1] + hor[i];
        }
        for(int i=0;i<n;i++){
            if(abs(pre[i]-suff[i])==hor[i]) return true;
        }
        vector<long long> pre1(m) , suff1(m);
        pre1[0] = ver[0];
        suff1[m-1] = ver[m-1];
        for(int i=1;i<m;i++){
            pre1[i] = pre1[i-1] + ver[i];
        }
        for(int i=m-2;i>=0;i--){
            suff1[i] = suff1[i+1] + ver[i];
        }
        for(int i=0;i<m;i++){
            if(abs(pre1[i]-suff1[i])==ver[i]) return true;
        }
        return false;
    }
};