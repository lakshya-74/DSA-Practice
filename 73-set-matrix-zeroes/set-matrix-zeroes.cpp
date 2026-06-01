class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) v.push_back({i,j});
            }
        }
        for(auto x:v){
            int k = x.first;
            for(int j=0;j<m;j++) matrix[k][j] = 0;
            k = x.second;
            for(int i=0;i<n;i++) matrix[i][k] = 0;
        }
    }
};