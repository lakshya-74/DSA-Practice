class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.size()<k) st.insert(nums[i]);
            else break;
        } 
        for(auto x:st){
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};