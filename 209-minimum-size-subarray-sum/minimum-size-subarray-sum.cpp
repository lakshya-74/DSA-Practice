class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i =0;
        int j =0;
        int n = nums.size();
        int ans = INT_MAX;
        int sum =0;
        while(i<=j && j<n){
            if(sum>=target){
                ans = min(ans,j-i);
                sum -= nums[i];
                i++;
            }
            else {
                sum += nums[j];
                j++;
            }
        }
        while(i<n){
            if(sum>=target){
                ans = min(ans,j-i);
                sum -= nums[i];
                i++;
            }
            else break;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};