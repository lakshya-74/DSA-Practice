class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r= 0 , ans = 0;
        int count = 0;
        while(r<n){
            if(nums[r]==0) count++;
            if(count>1){
                if(nums[l]==0) count--;
                l++;
            }
            if(count<=1) ans = max(ans,r-l+1);
            r++;
        }
        return ans-1;
    }
};