class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m= mat[0].size();
        vector<vector<int>> nums(n,vector<int>(m));
        nums = mat;
        k = k%m;
        while(k--){
            for(int i=0;i<n;i++){
                if(i&1==0){  // even
                    int temp = nums[i][0];
                    for(int j =1;j<m;j++){
                        nums[i][j-1] = nums[i][j];
                    }
                    nums[i][m-1] = temp;
                }
                else{  // odd
                    int temp = nums[i][m-1];
                    for(int j=m-1;j>0;j--){
                        nums[i][j] = nums[i][j-1];
                    }
                    nums[i][0] = temp;
                }
            }
        }    
        return nums==mat;
    }
};