class Solution {
public:
    void rotate(vector<int>& v,int k){
        int n = v.size();
        k = k%n;
        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> ans = arr;
        int sr = 0 , er = n-1;
        int sc = 0 , ec = m-1;
        while(sr<er && sc<ec){
            vector<int> v;
            for(int i=sr;i<=er;i++){
                v.push_back(arr[i][sc]);
            }

            for(int i=sc+1;i<=ec;i++){
                v.push_back(arr[er][i]);
            }

            for(int i=er-1;i>=sr;i--){
                v.push_back(arr[i][ec]);
            }

            for(int i=ec-1;i>sc;i--){
                v.push_back(arr[sr][i]);
            }

            rotate(v,k);
            int idx = 0;
            
            for(int i=sr;i<=er;i++){
                ans[i][sc] = v[idx++];
            }

            for(int i=sc+1;i<=ec;i++){
                ans[er][i] = v[idx++];
            }

            for(int i=er-1;i>=sr;i--){
                ans[i][ec] = v[idx++];
            }

            for(int i=ec-1;i>sc;i--){
                ans[sr][i] = v[idx++];
            }

            sr++;
            sc++;
            er--;
            ec--;
        }
        return ans;
    }
};