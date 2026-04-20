class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                for(int j=0;j<n;j++){
                    if(nums[j]==2){
                        ans = min(ans,abs(j-i));
                    }
                }
            }
        }
        return ans==n?-1:ans;
    }
};