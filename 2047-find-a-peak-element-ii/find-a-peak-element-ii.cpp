class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int lo = 0;
        int hi = m-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int mx = -1;
            int mx_idx = 0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mx){
                    mx = mat[i][mid];
                    mx_idx = i;
                }
            }
            int left = mid>0 ? mat[mx_idx][mid-1]:-1;
            int right = mid<m-1 ? mat[mx_idx][mid+1]:-1;
            if(mat[mx_idx][mid]>left && mat[mx_idx][mid]>right) return {mx_idx,mid};
            if(mat[mx_idx][mid]<left) hi = mid-1;
            else lo = mid+1;
        }
        return {0};
    }
};