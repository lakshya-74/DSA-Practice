class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suff(n);
        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = min(suff[i+1],nums[i]);
        }
        int mx = -1;
        for(int i=0;i<n;i++){
            mx = max(nums[i],mx);
            int x = mx - suff[i];
            if(x<=k) return i;
        }
        return -1;
    }
};