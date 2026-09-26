class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int i=0;
        while(i<n){
            if(nums[i]==0){
                if(i>=n-2) return -1;
                nums[i] = 1;
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
                ans++;
            }
            i++;
        }
        return ans;
    }
};