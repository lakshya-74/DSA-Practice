class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i]) != mpp.end() && (i - mpp[nums[i]])<=k) return true;
            mpp[nums[i]] = i;
        }
        return false;
    }
};