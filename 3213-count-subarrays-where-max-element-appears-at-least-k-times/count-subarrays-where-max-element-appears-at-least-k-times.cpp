class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = nums[0];
        for(int i=0;i<n;i++) mx = max(mx,nums[i]);
        long long l = 0 ,r = 0 , ans = 0;
        long long count = 0;
        while(r<n){
            if(nums[r]==mx) count++;
            while(count>=k){
                if(nums[l]==mx) count--;
                l++;
            }
            if(count<k) ans += l;
            r++;
        }
        return ans;
    }
};