class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long long val = nums[i];
            while(ans.size() && ans.back()==val){
                val *= 2;
                ans.pop_back();
            }
            ans.push_back(val);
        }
        return ans;
    }
};