class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int mn = INT_MAX;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[lo]<=nums[mid]){ // left part sorted 
                mn = min(mn,nums[lo]);
                lo = mid+1;
            }
            else{
                mn = min(mn,nums[mid]);
                hi = mid-1;
            }
        }
        return mn;
    }
};