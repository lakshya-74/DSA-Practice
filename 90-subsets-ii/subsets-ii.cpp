class Solution {
public:
    void rec(int idx ,vector<int>& nums,vector<int>& v ,vector<vector<int>>& ans){
        ans.push_back(v);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            rec(i+1,nums,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        rec(0,nums,v,ans);
        return ans;
    }
};