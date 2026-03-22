class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(mat==target) return true;
        vector<vector<int>> temp(n,vector<int>(n));
        for(int k = 0;k<3;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[j][n-i-1] = mat[i][j];
                }
            }
            if(temp==target) return true;
            mat = temp;
        }
        return false;
    }
};