class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int total = nums[0];
        sort(nums.begin()+1,nums.begin()+nums.size());
        total += nums[1] + nums[2];
        return total;
    }
};