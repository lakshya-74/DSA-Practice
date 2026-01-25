class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return 0;
        int mn = INT_MAX;
        int i = 0;
        int j = k-1;
        while(j<nums.size()){
            mn = min(mn,nums[j]-nums[i]);
            i++;
            j++;
        }
        return mn;
    }
};