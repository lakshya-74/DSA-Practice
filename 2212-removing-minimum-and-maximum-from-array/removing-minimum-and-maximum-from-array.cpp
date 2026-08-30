class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mnidx = -1 , mxidx = -1;
        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn = nums[i];
                mnidx = i;
            }
            if(nums[i]>mx){
                mx = nums[i];
                mxidx = i;
            }
        }
        int ans1 = 0;
        ans1 += min(mnidx+1,n-mnidx);
        ans1 += min(mxidx+1,n-mxidx);
        int ans2 = max(mnidx,mxidx) +1;
        int ans3 = n - min(mnidx,mxidx);
        return min({ans1,ans2,ans3});
    }
};