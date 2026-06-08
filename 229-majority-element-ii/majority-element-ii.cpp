class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int> ans;
        int n = nums.size();
        for(auto [x,y]:mpp){
            if(y>(n/3)) ans.push_back(x);
        }
        return ans;
    }
};