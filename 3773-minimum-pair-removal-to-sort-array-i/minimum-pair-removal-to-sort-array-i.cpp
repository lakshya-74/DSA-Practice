class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        while(!is_sorted(nums.begin(),nums.end())){
            if(nums.size()<2) break;
            vector<int> ans;
            int idx = -1;
            int sum = INT_MAX;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<sum){
                    sum = nums[i] + nums[i+1];
                    idx = i;
                }
            }
            for(int i=0;i<idx;i++){
                ans.push_back(nums[i]);
            }
            ans.push_back(sum);
            for(int i=idx+2;i<nums.size();i++){
                ans.push_back(nums[i]);
            }
            nums = ans;
            count++;
        }
        return count;
    }
};