class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        // if(k==1){
        //     return vector<vector<int>> (n,vector<int>(m,0));
        // }
        vector<vector<int>> v(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                    vector<int> temp;
                    for(int a =i;a<i+k;a++){
                        for(int b=j;b<j+k;b++){
                            temp.push_back(grid[a][b]);
                        }
                    }
                    int ans = INT_MAX;
                    sort(temp.begin(),temp.end());
                    for(int a=0;a<temp.size()-1;a++){
                        if(temp[a]!=temp[a+1]){
                            ans = min(ans,abs(temp[a]-temp[a+1]));
                        }
                    }
                    if(ans!=INT_MAX) v[i][j] = ans;
            }
        }
        return v;
    }
};