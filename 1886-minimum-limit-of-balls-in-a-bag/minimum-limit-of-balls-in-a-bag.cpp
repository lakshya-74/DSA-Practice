class Solution {
public:
    bool check(int mid , vector<int>& nums , int mxop){
        long long count =0;
        for(int i=0;i<nums.size();i++){
            count += (nums[i]-1)/mid;
            if(count>mxop) return false;
        }
        return count<=mxop;
    }
    int minimumSize(vector<int>& nums, int mxop) {
        int n = nums.size();
        int ans = 0;
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,nums,mxop)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};