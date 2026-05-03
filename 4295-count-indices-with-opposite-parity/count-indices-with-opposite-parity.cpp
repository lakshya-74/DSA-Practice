class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n-1;i++){
            int count =0;
            for(int j=i+1;j<n;j++){
                if(nums[i]%2 != nums[j]%2) count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};