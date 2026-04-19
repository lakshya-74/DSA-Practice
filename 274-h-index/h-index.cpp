class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lo = 0;
        int hi = n-1;
        int ans=0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if((n-mid)<=nums[mid]){
                ans = n-mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};