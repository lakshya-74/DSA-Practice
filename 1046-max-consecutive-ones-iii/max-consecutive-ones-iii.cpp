class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        // think in the way like "longest subarray that contain atmost k zeros"
        int zeros = 0;
        while(r<n){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k){
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};