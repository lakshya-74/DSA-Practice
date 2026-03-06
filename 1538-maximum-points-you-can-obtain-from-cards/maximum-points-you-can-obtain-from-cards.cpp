class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lsum = 0;
        int rsum = 0;
        int ans = 0;
        for(int i=0;i<k;i++){
            lsum += nums[i];
        }
        ans = lsum;
        int ridx = n-1;
        for(int i=k-1;i>=0;i--){
            lsum -= nums[i];
            rsum += nums[ridx];
            ridx--;
            ans = max(ans,lsum+rsum);
        }
        return ans;
    }
};