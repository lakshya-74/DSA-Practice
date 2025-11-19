class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int val = original;
        while(1){
            int i;
            for( i=0;i<nums.size();i++){
                if(nums[i]==original){
                    original *= 2;
                    break;
                }
            }
            if(i==nums.size()) break;
        }
        return original;
    }
};