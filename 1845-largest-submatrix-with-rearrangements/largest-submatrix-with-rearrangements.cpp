class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> v = nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==1){
                    if(i>0){
                        v[i][j] += v[i-1][j];
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            sort(v[i].rbegin(),v[i].rend());
            for(int j=0;j<m;j++){
                int area = v[i][j]*(j+1);
                ans = max(ans,area);
            }
        }
        return ans;
    }
};