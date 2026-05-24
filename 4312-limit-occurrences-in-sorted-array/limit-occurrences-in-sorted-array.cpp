class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            int x = min(k,mpp[nums[i]]);
            for(int j=0;j<x;j++){
                ans.push_back(nums[i]);
            }
            mpp.erase(nums[i]);
        }
        return ans;
    }
};