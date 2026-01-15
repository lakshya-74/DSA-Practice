class Solution {
public:
    bool check(vector<int>& nums,int mid ,int k){
        int count = 1;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum += nums[i];
            }
            else{
                count++;
                sum = nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = nums[0];
        int sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            mx = max(mx,nums[i]);
        }
        int lo = mx;
        int hi = sum;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(nums,mid,k)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};