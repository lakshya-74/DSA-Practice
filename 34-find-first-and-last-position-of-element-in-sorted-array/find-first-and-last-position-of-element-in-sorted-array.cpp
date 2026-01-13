class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int lo = 0;
        int hi = nums.size()-1;
        int mn = 0;
        int mx = nums.size();
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>=target){
                mn = mid;
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        lo =0;
        hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>target){
                mx = mid;
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        if((nums[mn]!=target) && (mx==0 || nums[mx-1]!=target)) return {-1,-1}; 
        return {mn,mx-1};
    }
};