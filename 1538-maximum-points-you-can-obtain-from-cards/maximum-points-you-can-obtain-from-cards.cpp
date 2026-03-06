class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        // int lsum = 0;
        // int rsum = 0;
        int ans = 0;
        // for(int i=0;i<k;i++){
        //     lsum += nums[i];
        // }
        // ans = lsum;
        // int ridx = n-1;
        // for(int i=k-1;i>=0;i--){
        //     lsum -= nums[i];
        //     rsum += nums[ridx];
        //     ridx--;
        //     ans = max(ans,lsum+rsum);
        // }
        // return ans;

        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        int curr = 0;
        for(int i=0;i<n-k;i++) curr += nums[i];
        ans = total-curr;
        int l=0,r=n-k-1;
        while(r<n-1){
            curr -= nums[l];
            l++;
            r++;
            curr += nums[r];
            ans = max(ans,total-curr);
        }
        return ans;
    }
};