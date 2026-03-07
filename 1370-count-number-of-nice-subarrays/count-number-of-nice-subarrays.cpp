class Solution {
public:
    int check(vector<int>& nums ,int k){
        int l = 0 , r =0 , ans = 0 , sum = 0;
        int n = nums.size();
        while(r<n){
            if(nums[r]&1) sum++;
            while(sum>k){
                if(nums[l]&1) sum--;
                l++;
            }
            if(sum<=k){
                ans += (r-l+1);
            }
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return check(nums,k) - check(nums,k-1);
    }
};