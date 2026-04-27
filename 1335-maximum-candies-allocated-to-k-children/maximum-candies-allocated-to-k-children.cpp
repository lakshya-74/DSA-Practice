class Solution {
public:
    bool check(int mid , vector<int>& nums, long long k){
        long long count = 0;
        for(int i=0;i<nums.size();i++){
            count += nums[i]/mid;
            if(count>=k) return true;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        int ans = 0;
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,nums,k)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};