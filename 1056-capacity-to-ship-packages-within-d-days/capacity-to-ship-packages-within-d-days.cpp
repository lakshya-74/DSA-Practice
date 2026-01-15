class Solution {
public:
    bool check(vector<int>& nums,int mid,int days){
        int sum = 0;
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum += nums[i];
            }
            else{
                sum = nums[i];
                count++;
            }
        }
        count += (sum+mid-1)/mid;
        return count<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int sum = 0;
        int n = nums.size();
        int mx = nums[0];
        for(int i=0;i<n;i++){
            sum += nums[i];
            mx = max(mx,nums[i]);
        }
        int lo = mx;
        int hi = sum;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(nums,mid,days)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};