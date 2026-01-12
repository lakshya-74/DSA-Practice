class Solution {
public:
    void rec(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>& v){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        // take 
        v.push_back(nums[i]);
        rec(i+1,nums,ans,v);
        // dont take
        v.pop_back();
        rec(i+1,nums,ans,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        rec(0,nums,ans,v);
        return ans;
    }
};