class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans = nums[lo];
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[lo]<=nums[mid]){
                ans = min(ans,nums[lo]);
                lo = mid+1;
            }
            else hi = mid;
        }
        return ans;
    }
};