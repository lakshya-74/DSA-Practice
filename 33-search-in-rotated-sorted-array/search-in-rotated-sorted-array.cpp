class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int idx = -1;
        // obervation : one part is sorted from mid
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                idx = mid;
                break;
            }
            // check for which part is sorted
            if(nums[lo]<=nums[mid]){ // left part is sorted
                // checking target is present in left side or not
                if(target>=nums[lo] && target<=nums[mid]){
                    hi = mid-1;
                }
                // target element is in right side
                else{
                    lo = mid+1;
                }
            }
            // right side is sorted
            else{
                // check target is present in right side or not
                if(target>=nums[mid] && target<=nums[hi]){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        return idx;
    }
};