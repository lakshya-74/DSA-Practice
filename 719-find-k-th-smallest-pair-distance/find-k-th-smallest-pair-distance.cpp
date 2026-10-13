class Solution {
public:
    int check(int diff, vector<int>& nums){
        int count =0;
        int n = nums.size();
        int j = 0;
        for(int i=0;i<n;i++){
            while(nums[i]-nums[j]>diff) j++;
            count += i-j;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lo = 0;
        int hi = nums[n-1] - nums[0];
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,nums)>=k){
                hi = mid;
            }
            else lo = mid+1;
        }
        return lo;
    }
};