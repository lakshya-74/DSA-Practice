class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int k=0;
        vector<int> arr(n*m);
        bool flag = true;
        int rem;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[k++] = grid[i][j];
                if(i==0 && j==0) rem = grid[i][j]%x;
                else if (rem!=(grid[i][j]%x)) return -1;
            }
        }
        sort(arr.begin(),arr.end());
        int l = arr.size()/2;
        int num = arr[l];
        int count =0;
        for(int i=0;i<n*m;i++){
            count += abs(arr[i]-num)/x;
        }
        return count;
    }
};