class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        vector<int> ans;
        for(int i=mn+1;i<mx;i++){
            if(mpp.find(i)==mpp.end()) ans.push_back(i);
        }
        return ans;
    }
};