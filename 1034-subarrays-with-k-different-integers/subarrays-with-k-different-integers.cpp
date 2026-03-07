class Solution {
public:
    int check(vector<int>& nums, int k){
        int l =0 , r =0 , count = 0;
        int n = nums.size();
        map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size()<=k){
                count += r-l+1;
            }
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return check(nums,k) - check(nums,k-1);
    }
};