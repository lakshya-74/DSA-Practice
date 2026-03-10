class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();
        int l =0 , r = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        while(r<n){
            mn = min(mn,nums[r]);
            mx = nums[r];
            if(mx-mn>k){
                count++;
                mx = nums[r];
                mn = nums[r];
            }
            r++;
        }
        return count+1;
    }
};