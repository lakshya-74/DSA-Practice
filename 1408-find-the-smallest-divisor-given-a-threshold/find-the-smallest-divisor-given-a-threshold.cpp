class Solution {
public:
    bool check(vector<int>& nums,int x,int mid){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int a = (nums[i]+mid-1)/mid;
            sum += a;
        }
        return sum<=x;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
        }
        int lo = 1;
        int hi = mx;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(nums,threshold,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid +1;
        }
        return ans;
    }
};