class Solution {
public:
    bool check(vector<int>& nums ,int mid,int m,int k){
        int count =0;
        int mx = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
            }
            else{
                mx += count/k;
                count = 0;
            }    
        }
        mx += count/k;
        return mx>=m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int mx = nums[0];
        int mn = INT_MAX;
        int n = nums.size();
        if((long long)m*(long long)k>n) return -1;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            mn = min(mn,nums[i]);
        }
        int lo = mn;
        int hi = mx;
        int ans = hi;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(nums,mid,m,k)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};