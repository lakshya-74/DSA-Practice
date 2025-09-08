class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[0]==nums[i]) count++;
        }
        if(count==nums.size()) return 0;
        return 1;
    }
};