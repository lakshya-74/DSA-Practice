class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int sm_odd = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                sm_odd = min(sm_odd,nums[i]);
            }
        }
        bool even_check = true;
        //check for even 
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                even_check = false;
                break;
            }
        }
        if(even_check) return true;
        // check for odd
        for(int i=0;i<n;i++){
            if(!(nums[i]&1)){
                if(nums[i]-sm_odd<1) return false;
            }
        }
        return true;
    }
};