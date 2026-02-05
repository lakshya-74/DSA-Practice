class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int val = abs(nums[i]);
            if(val==0) ans[i] = 0;
            else if(nums[i]>0){
                int j = (i+val)%n;
                ans[i] = nums[j]; 
            }
            else{
                int j = ((i-val)%n + n)%n;
                ans[i] = nums[j];
            }
        }
        return ans;
    }
};